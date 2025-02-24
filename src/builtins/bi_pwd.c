#include "../../inc/minishell.h"

/**
 * bi_pwd:
 *	Executes the pwd builtin command: prints the working directory.
 *	Returns 1 on completion.
 */
void  bi_pwd(void)
{
  char  *answer;

  answer = getcwd(NULL, 0);
  printf("%s\n", answer);
  free(answer);
}
