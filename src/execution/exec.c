#include "../../inc/minishell.h"

void    exec_rd(t_redirect *rd)
{
    int fd;

    while (rd)
    {
        if (rd->type == T_REDIR_IN)
            fd = open(rd->file, O_RDONLY);
        else if (rd->type == T_REDIR_OUT)
            fd = open(rd->file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
        else if (rd->type == T_REDIR_APP)
            fd = open(rd->file, O_CREAT | O_APPEND | O_WRONLY, 0644);
        else if (rd->type == T_HEREDOC)
            fd = create_heredoc(rd);

        if (fd < 0)
            ft_putstr_fd("Error: Failed to open fd\n", 2);
        handle_redir(rd, fd);
        rd = rd->next;
    }
}

void    exec_cmd(ast_node *node, t_shell *shell)
{
    int     pid;
    t_exec  exec;

    if (!node->args || !node->args[0])
        return ;
    pid = fork();
    if (pid == -1)
        ft_putstr_fd("Error: Failed to fork\n", 2);
    else if (pid == 0)
    {
        exec_rd(node->rd);
        extract_paths(&exec, shell->env_ll);
        check_path(&exec, node);
        if (execve(exec.cmd, node->args, shell->env) == -1)
            ft_putstr_fd("Error: Execve failed\n", 2);
    }
    else
        waitpid(pid, &shell->exit, 0);
}

void    exec_pipe(ast_node *node, t_shell *shell)
{
    int pipe_fd[2];
    int std_out;
    int std_in;

    if (pipe(pipe_fd) == -1)
    {
        ft_putstr_fd("Error: Failed to pipe\n", 2);
        return ;
    }
    // Redirect STDOUT to pipe write end (LEFT)
    std_out = dup(STDOUT_FILENO);
    if  (std_out == -1)
    {
        ft_putstr_fd("Error: Failed to dup STDOUT\n", 2);
        return ;
    }
    if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
    {
        ft_putstr_fd("Error: Failed to dup2 write end\n", 2);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        return ;
    }
    close(pipe_fd[1]);
    exec_ast(node->left, shell);
    // Restore STDOUT
    if (dup2(std_out, STDOUT_FILENO) == -1)
    {
        ft_putstr_fd("Error: Failed to restore STDOUT\n", 2);
        close(std_out);
        return ;
    }
    close(std_out);
    // Redirect STDOUT to pipe write end (RIGHT)
    std_in = dup(STDIN_FILENO);
    if (std_in == -1)
    {
        ft_putstr_fd("Error: Failed to dup STDIN\n", 2);
        return ;
    }
    if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
    {
        ft_putstr_fd("Error: Failed to dup2 read end\n", 2);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        return ;
    }
    close(pipe_fd[0]);
    exec_ast(node->right, shell);
    // Restore STDIN
    if (dup2(std_in, STDIN_FILENO) == -1)
    {
        ft_putstr_fd("Error: Failed to restore STDIN\n", 2);
        close(std_in);
        return ;
    }
    close(std_in);
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
