#include "../../inc/minishell.h"

int isdigit_str(char *args)
{
  int i;

  i = 0;
  while (args[i] != '\0')
  {
    if (!ft_isdigit(args[i]))
    {
      return (1);
    }
    i++;
  }
  return (0);
}

/**
 * bi_exit:
 *	Executes the exit builtin command: exits the shell with a specified
 *	exit status. If a non-numeric argument is provided, an error message
 *	is displayed and the function returns without exiting. If the argument
 *	is a number, it is converted to a long long, and the shell exits with
 *	the status obtained by taking the argument modulo 256. If no argument
 *	is given, the shell exits with status 0.
 *	@args: array of command arguments where args[0] is "exit" and args[1]
 *	is the optional exit status.
 */
void  bi_exit(t_shell *sh_atr, char **args)
{
  int status;
  int err;

  status = 0;
  err = 0;
  if (args != NULL || args[1] != NULL)
  {
    if (isdigit_str(args[1]))
    {
      printf("bash: exit: %s: numeric argument required\n", args[1]);
      return ;
    }
    status = ft_atoi(args[1]) % 256;
    if (status < 0)
      status = status + 256;
  }
  else
  {
    status = sh_atr->exit;
  }
  free_every(sh_atr);
  exit(status);
}
