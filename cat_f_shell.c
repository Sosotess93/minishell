/*
** cat_f_shell.c for  in /home/mellit_r/PSU_2014_minishell1
** 
** Made by Ramzi Melliti
** Login   <mellit_r@epitech.net>
** 
** Started on  Sat Jan 31 16:06:59 2015 Ramzi Melliti
** Last update Tue Mar 10 15:54:54 2015 Ramzi Melliti
*/

#include "mnsh.h"

char	*cat_f_shell(char *dest, char *src)
{
  int   a;
  int   i;

  i = my_strlen(dest);
  a = 0;
  dest[i] = '/';
  while (src[a] != '\0')
    {
      i = i + 1;
      dest[i] = src[a];
      a = a + 1;
    }
  i = i + 1;
  dest[i] = '\0';
  return (dest);
}
