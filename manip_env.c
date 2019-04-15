/*
** manip_env.c for  in /home/mellit_r/PSU/PSU_2014_minishell1
** 
** Made by Ramzi Melliti
** Login   <mellit_r@epitech.net>
** 
** Started on  Tue Mar  3 18:32:18 2015 Ramzi Melliti
** Last update Sun Mar 15 16:07:12 2015 Sofiane Charrad
*/

#include "mnsh.h"

int	check_env(char **env)
{
  int	i;
  int	a;

  i = 0;
  if (env[0] == NULL)
    {
      my_putstr("Env is missing\n");
      return (1);
    }
  while (env[i] != NULL)
    {
      if (env[i][0] == 'P' && env[i][1] == 'A' &&
	  env[i][2] == 'T' && env[i][3] == 'H' &&
	  env[i][4] == '=')
	a = 1;
      i = i + 1;
    }
  if (a != 1)
    {
      my_putstr("PATH is missing.\n");
      return (1);
    }
  return (0);
}

int	count_env(char **my_env)
{
  int	nb;

  nb = 0;
  while (my_env[nb] != 0)
    nb = nb + 1;
  return (nb);
}

char	**cpy_env(char **env, char **my_env)
{
  int   i;
  int   nb;
  
  i = 0;
  nb = 0;
  while (env[i] != 0)
    {
      nb = nb + 1;
      i = i + 1;
    }
  if ((my_env = malloc(sizeof(char *) * (nb * nb))) == NULL)
    {
      my_putstr("Malloc failed.");
      return (NULL);
    }
  i = 0;
  while (env[i] != 0)
    {
      my_env[i] = env[i];
      i = i + 1;
    }
  return (my_env);
}

char	**manip_env(char **env, char **my_env)
{
  if (check_env(env) == 1)
    return (NULL);
  if ((my_env = cpy_env(env, my_env)) == NULL)
    return (NULL);
  return(my_env);
}
