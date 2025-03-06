#include "../../inc/minishell.h"

void exec_rd(t_redirect *rd)
{
    int fd = -1;
    int last_heredoc_fd = -1;

    while (rd)
    {
        if (rd->type == T_REDIR_IN)
            fd = open(rd->file, O_RDONLY);
        else if (rd->type == T_REDIR_OUT)
            fd = open(rd->file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
        else if (rd->type == T_REDIR_APP)
            fd = open(rd->file, O_CREAT | O_APPEND | O_WRONLY, 0644);
        else if (rd->type == T_HEREDOC)
        {
            // Close previous heredoc since we only use the last one
            if (last_heredoc_fd != -1)
                close(last_heredoc_fd);

            last_heredoc_fd = create_heredoc(rd);
            if (last_heredoc_fd == -1)
            {
                ft_putstr_fd("Error: Failed to create heredoc\n", 2);
                return;
            }
            fd = last_heredoc_fd;
        }

        if (fd < 0)
        {
            ft_putstr_fd("Error: Failed to open fd\n", 2);
            return;
        }

        // Apply redirection for output files immediately
        if (rd->type == T_REDIR_OUT || rd->type == T_REDIR_APP || rd->type == T_REDIR_IN)
            handle_redir(rd, fd);
        rd = rd->next;
    }
    // Redirect only the last heredoc to STDIN
    if (last_heredoc_fd != -1)
        handle_redir(NULL, last_heredoc_fd);
}

void    exec_cmd(ast_node *node, t_shell *shell)
{
    int     pid;
    t_exec  exec;
    
    pid = fork();
    if (pid == -1)
        ft_putstr_fd("Error: Failed to fork\n", 2);
    else if (pid == 0)
    {
        reset_signals_in_child();
        exec_rd(node->rd);
        if (node->args && node->args[0])
        {
            extract_paths(&exec, shell->env_ll);
            check_path(&exec, node);
            shell->exit = execve(exec.cmd, node->args, shell->env);
            if (shell->exit == -1)
            {
                ft_putstr_fd("Error: Execve failed\n", 2);
                exit(WEXITSTATUS(shell->exit));
            }
        }
        else
            exit(0);
    }
    else
        waitpid(pid, &shell->exit, 0);
}

void    exec_pipe(ast_node *node, t_shell *shell)
{
    int pipe_fd[2];
    int pid_l;
    int pid_r;

    if (pipe(pipe_fd) == -1)
        ft_putstr_fd("Error: Failed to pipe\n", 2);
    pid_l = fork();
    if (pid_l < 0)
        ft_putstr_fd("Error: Failed to fork left\n", 2);
    else if (pid_l == 0)
    {
        close(pipe_fd[0]);
        if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
        {
            close(pipe_fd[1]);
            ft_putstr_fd("Error: Failed to dup2 left\n", 2);
            exit (1);
        }
        close(pipe_fd[1]);
        exec_ast(node->left, shell);
        exit(0);
    }
    pid_r = fork();
    if (pid_r < 0)
        ft_putstr_fd("Error: Failed to fork right\n", 2);
    else if (pid_r == 0)
    {
        close(pipe_fd[1]);
        if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
        {
            close(pipe_fd[0]);
            ft_putstr_fd("Error: Failed to dup2 right\n", 2);
            exit (1);
        }
        close(pipe_fd[0]);
        exec_ast(node->right, shell);
        exit(0);
    }
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    waitpid(pid_l, NULL, 0);
    waitpid(pid_r, &shell->exit, 0);
}

void    exec_ast(ast_node *node, t_shell *shell)
{
    if (!node)
        return ;
    if (node->type == AST_CMD)
        exec_cmd(node, shell);
    else if (node->type == AST_PIPE)
        exec_pipe(node, shell);
}
