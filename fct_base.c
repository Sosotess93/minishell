/*
** fct_base.c for fct_base in /home/charra_s/Minishell2 [Maj]
** 
** Made by Sofiane Charrad
** Login   <charra_s@epitech.net>
** 
** Started on  Sat Mar 14 15:48:26 2015 Sofiane Charrad
** Last update Sat Mar 14 16:52:51 2015 Sofiane Charrad
*/

#include "mnsh.h"

char    *my_strdup(char *src)
{
  char  *s;
  int   soso;
  int   i;

  i = 0;
  soso = my_strlen(src);
  s = malloc(soso);
  while (src[i] != '\0')
    {
      s[i] = src[i];
      i = i + 1;
    }
  return (s);
}

char    *my_strcat(char *dest, char *src)
{
  int   i;
  int   j;

  j = 0;
  i = my_strlen(dest);
  while (src[j])
    dest[i++] = src[j++];
  dest[i] = '\0';
  return (dest);
}
