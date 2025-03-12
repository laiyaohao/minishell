#include "../../inc/minishell.h"

void  del_env(char **env, int i, t_list **env_ll)
{
  // find env
  t_list  *node;
  // t_list  *to_b_del;
  // t_list  *fut_next;
  t_list  *prev;

  node = *env_ll;
  if (node != NULL && ((t_env *)(node->content))->key == env[i])
  {
    *env_ll = node->next;
    free(node);
    return ;
  }
  while (node != NULL && ft_strncmp(((t_env *)(node->content))->key, env[i], ft_strlen(env[i]))
    )
  {
    printf("((t_env *)(node->content))->key: %s\n", ((t_env *)(node->content))->key);
    prev = node;
    node = node->next;
  }
  if (node == NULL)
  {
    printf("zhao bu dao\n");
    return ;
  }
  // now node is the content to be deleted.
  // find node's next's next address
  // fut_next = node->next->next;
  // printf("here\n");
  // to_b_del = node->next;
  // node->next = fut_next;
  prev->next = node->next;
  free_node(node->content);
  free(node);
}

// void delete_node(t_node **head, int value) {
//     t_node *temp = *head;
//     t_node *prev = NULL;

//     // Case 1: Deleting the head node
//     if (temp != NULL && temp->data == value) {
//         *head = temp->next; // Move head to next node
//         free(temp); // Free old head
//         return;
//     }

//     // Case 2: Search for the node to delete
//     while (temp != NULL && temp->data != value) {
//         prev = temp;
//         temp = temp->next;
//     }

//     // If the node wasn't found
//     if (temp == NULL)
//         return;

//     // Unlink the node from the list
//     prev->next = temp->next;
//     free(temp);
// }