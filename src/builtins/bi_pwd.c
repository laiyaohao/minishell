#include "../../inc/minishell.h"

void  bi_pwd(void)
{
  char  *answer;

  answer = getcwd(NULL, 0);
  printf("%s\n", answer);
  free(answer);
}
