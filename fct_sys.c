/*
** fct.c for fct in /home/charra_s/rendu/my_str_to_word_tab/str_to_wordtab
** 
** Made by Sofiane Charrad
** Login   <charra_s@epitech.net>
** 
** Started on  Thu Jan 29 19:00:29 2015 Sofiane Charrad
** Last update Sat Mar 14 20:18:17 2015 Sofiane Charrad
*/


#include	"mnsh.h"

int	my_strstr(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i])
    {
      if (s1[i] < s2[i])
	return (-1);
      else if (s1[i] > s2[i])
	return (1);
      else
	return (0);
      i++;
    }
  if (s1[i] < s2[i])
    return (-1);
  else if (s1[i] > s2[i])
    return (1);
  else
    return (0);
}
