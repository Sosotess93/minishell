/*
** main.c for  in /home/mellit_r/PSU_2014_minishell1
** 
** Made by Ramzi Melliti
** Login   <mellit_r@epitech.net>
** 
** Started on  Wed Jan 21 13:21:52 2015 Ramzi Melliti
** Last update Sat Mar 14 22:09:38 2015 Sofiane Charrad
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"
#include "mnsh.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

int	prompt(char **my_env, int n)
{
  int	i;
  int	s;
  char *str;

  i = 8;
  s = 0;
  write(1, "\033[1;33;40m", 10);
  my_putstr1("\n[", 1);
  while (my_env[s] != 0)
    {
      if (my_env[s][0] == 'L' && my_env[s][1] == 'O' &&
	  my_env[s][2] == 'G' && my_env[s][3] == 'N')
	{
	  while (my_env[s][i] != '\0')
	    {
	      my_putchar(my_env[s][i]);
	      i = i + 1;
	    }
	  my_putchar(']');
	  my_putstr(" command #");
	  my_put_nbr(n);
	  my_putstr(" >");
	  my_putstr("\033[0m ");
	  //	  write(1, "\033[0m", 10);
	  //	  my_putstr(" ");
	  return (0);
	}
      s = s + 1;
    }
}

int    minishell(char **my_env)
{
  char	buf[1000];
  int   ret;
  int	i;
  int	n;

  //  g_prmt->pwd = my_getpwd();
  n = 1;
  while (42)
    {
      prompt(my_env, n);
      //      prompt_deux();
      ret = read(0, buf, 1000);
      if (check(ret) == 1)
	return (1);
      buf[ret] = '\0';
      ret = is_builtin(my_env, buf);
      if (ret == 1)
	return (1);
      else if (ret == 0 || ret == -1)
	my_putchar('\n');
      else 
	if (recup(buf, my_env) == 1)
	  return (1);
      n = n + 1;
    }
  return (0);
}
