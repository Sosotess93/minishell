/*
** recup.c for  in /home/mellit_r
** 
** Made by Ramzi Melliti
** Login   <mellit_r@epitech.net>
** 
** Started on  Thu Jan 29 19:15:17 2015 Ramzi Melliti
** Last update Sat Mar 14 16:52:30 2015 Sofiane Charrad
*/

#include "mnsh.h"

int			recup(char *str, char **my_env)
{
  struct s_path		var;
  struct s_recup	val;

  val.i = 0;
  val.tab = path(my_env, &var);
  val.rec = my_str_to_wordtab(str);
  while (val.tab[val.i] != NULL)
    {
      val.cat = cat_f_shell(val.tab[val.i], val.rec[0]);
      val.c = access(val.cat, F_OK | R_OK | X_OK);
      if (val.c == 0)
	{
	  if (go_fork(val.cat, val.rec, my_env) == 1)
	    return (1);
	  return (0);
	}
      val.i = val.i + 1;
    }
  if (check_access(val.c) == -1)
    return (0);
  return (0);
}
