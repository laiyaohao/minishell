#include "../../inc/minishell.h"

void print_redirections(t_redirect *rd, int level)
{
    while (rd)
    {
        for (int i = 0; i < level; i++)
            printf("  "); // Indentation for tree structure

        printf("  ↳ Redirection: ");
        if (rd->type == T_REDIR_IN)
            printf("< ");
        else if (rd->type == T_REDIR_OUT)
            printf("> ");
        else if (rd->type == T_REDIR_APP)
            printf(">> ");
        else if (rd->type == T_HEREDOC)
            printf("<< ");
        
        printf("%s\n", rd->file);
        rd = rd->next;
    }
}

void print_ast(ast_node *node, int level, const char *branch)
{
    if (!node)
        return;

    for (int i = 0; i < level; i++)
        printf("  "); // Indentation

    if (branch)
        printf("%s ", branch); // Show whether this is LEFT or RIGHT node

    if (node->type == AST_CMD)
    {
        printf("Command:\n");

        // Print each argument with indexing
        for (int i = 0; node->args && node->args[i]; i++)
        {
            for (int j = 0; j < level + 1; j++) // Additional indentation
                printf("  ");
            printf("  ├─ [Arg %d]: %s\n", i, node->args[i]);
        }

        // Print redirections at the same level as args
        print_redirections(node->rd, level + 1);
    }
    else if (node->type == AST_PIPE)
    {
        printf("Pipe:\n");
        print_ast(node->left, level + 1, "↖ Left ");
        print_ast(node->right, level + 1, "↘ Right");
    }
}

void debug_print_ast(ast_node *root)
{
    printf("======= AST Structure =======\n");
    print_ast(root, 0, NULL);
    printf("================================\n");
}

// void print_redirections(t_redirect *rd, int level)
// {
//     while (rd)
//     {
//         for (int i = 0; i < level; i++)
//             printf("  "); // Indentation for tree structure

//         printf("  ↳ Redirection: ");
//         if (rd->type == T_REDIR_IN)
//             printf("< ");
//         else if (rd->type == T_REDIR_OUT)
//             printf("> ");
//         else if (rd->type == T_REDIR_APP)
//             printf(">> ");
//         else if (rd->type == T_HEREDOC)
//             printf("<< ");
//         printf("%s\n", rd->file);
//         rd = rd->next;
//     }
// }

// void print_ast(ast_node *node, int level, const char *branch)
// {
//     if (!node)
//         return;

//     for (int i = 0; i < level; i++)
//         printf("  "); // Indentation

//     if (branch)
//         printf("%s ", branch); // Show whether this is LEFT or RIGHT node

//     if (node->type == AST_CMD)
//     {
//         printf("Command: ");
//         for (int i = 0; node->args && node->args[i]; i++)
//             printf("%s ", node->args[i]);
//         printf("\n");
//         print_redirections(node->rd, level + 1);
//     }
//     else if (node->type == AST_PIPE)
//     {
//         printf("Pipe:\n");
//         print_ast(node->left, level + 1, "↖ Left ");
//         print_ast(node->right, level + 1, "↘ Right");
//     }
// }

// void debug_print_ast(ast_node *root)
// {
//     printf("======= AST Structure =======\n");
//     print_ast(root, 0, NULL);
//     printf("================================\n");
// }
