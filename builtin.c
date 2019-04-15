/*
** builtin.c for  in /home/mellit_r/PSU/PSU_2014_minishell1
** 
** Made by Ramzi Melliti
** Login   <mellit_r@epitech.net>
** 
** Started on  Tue Mar 10 15:35:58 2015 Ramzi Melliti
** Last update Fri Mar 13 15:23:21 2015 Ramzi Melliti
*/

#include "mnsh.h"

int	is_exit(char *str)
{
  if (str[0] == 'e' && str[1] == 'x' &&
      str[2] == 'i' && str[3] == 't' && str[4] == '\n')
    return (0);
  else if (str[0] == 'q' && str[1] == 'u' &&
	   str[2] == 'i' && str[3] == 't' && str[4] == '\n')
    return (0);
  return (1);
}

int	is_next_line(char *str)
{
  if (str[0] == '\n')
    return (0);
  return (1);
}

/* int	is_unsetenv(char *str) */
/* { */
/* } */

int	is_setenv(char **my_env, char *str)
{
  char	**new_env;
  int	i;
  int	a;

  if (str[0] == 's' && str[1] == 'e' && str[2] == 't' && str[3] == 'e' &&
      str[4] == 'n' && str[5] == 'v')
    {
      i = count_env(my_env);
      if ((new_env = malloc(sizeof(char *) * i)) == NULL)
	return (1);
      if ((a = word(str)) == 1)
	return (1);
      str = new_line_env(str, a);
      new_env = my_env;
      new_env[i] = str;
      return (0);
    }
  return (-1);
}

int	is_builtin(char **my_env, char *str)
{
  int	i;

  if (is_exit(str) == 0)
      return (1);
  else if (is_next_line(str) == 0)
    return (0);
  i = is_setenv(my_env, str);
  if (i == 0)
      return (0);
  else if (i == 1)
    {
      my_putstr("You did something wrong. Read man of setenv.\n");
      return (-1);
    }
  return (2);
}
