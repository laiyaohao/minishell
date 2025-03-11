#include "../../inc/minishell.h"

void  free_every(t_shell *sh_atr)
{
  free(sh_atr->attr->full_line);
	free(sh_atr->attr->working_dir);
	free(sh_atr->attr->old_working_dir);
  free_env(&(sh_atr->env_ll));
}
