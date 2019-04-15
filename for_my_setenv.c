/*
** for_my_setenv.c for  in /home/mellit_r/PSU/PSU_2014_minishell1
** 
** Made by Ramzi Melliti
** Login   <mellit_r@epitech.net>
** 
** Started on  Thu Mar 12 13:27:35 2015 Ramzi Melliti
** Last update Sun Mar 15 20:28:07 2015 Sofiane Charrad
*/

#include "minishell.h"
#include "mnsh.h"

int	word(char *str)
{
  struct s_word v;

  v.i = 0;
  v.s = 0;
  /* if (str[v.i] == ' ') */
  /*   { */
  /*     while (str[v.i] == ' ') */
  /* 	v.i = v.i + 1; */
  /*   } */
  while (str[v.i] != '\0')
    {
      if (str[v.i] == ' ')
	{
	  v.s = v.s + 1;
	  v.r = v.i + 1;
	  while ((str[v.i] < 'A' && str[v.i] > 'Z') ||
		 (str[v.i] < 'a' && str[v.i] > 'z') || (str[v.i] < '0' && str[v.i] > '9'))
	    v.i = v.i + 1;
	}
      v.i = v.i + 1;
    }
  if (v.s != 1)
    return (1);
  return (v.r);
}

char	*new_line_env(char *str, int i)
{
  char	*dest;
  int	s;

  dest = malloc(sizeof(char *) +1);
  s = 0;
  while (str[i] != '\0')
    {
      dest[s] = str[i];
      i = i + 1;
      s = s + 1;
    }
  dest[s - 1] = '\0';
  return (dest);
}

