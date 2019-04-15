/*
** str_to_wordtab.c for  in /home/mellit_r/TP
** 
** Made by Ramzi Melliti
** Login   <mellit_r@epitech.net>
** 
** Started on  Mon Jan 19 15:04:02 2015 Ramzi Melliti
** Last update Fri Mar 13 15:52:18 2015 Ramzi Melliti
*/

#include "mnsh.h"

char	*words(char *st, int i)
{
  char	*tab;
  int	j;

  j = 0;
  tab = malloc(((my_strlen(st)) * sizeof(char)));
  while (st[i] != '\0')
    {
      if ((st[i] <= 'Z' && st[i] >= 'A') || (st[i] <= 'z' && st[i] >= 'a') ||
	  (st[i] >= '9' && st[i] <= '0') || st[i] == '-')
	{
	  while ((st[i] >= 'A' && st[i] <= 'Z') || (st[i] >= 'a' && st[i] <= 'z') ||
		 (st[i] >= '0' && st[i] <= '9') || st[i] != '\0')
	    {
	      tab[j] = st[i];
	      i = i + 1;
	      j = j + 1;
	      if (!((st[i] <= 'Z' && st[i] >= 'A') || 
		   (st[i] <= 'z' && st[i] >= 'a') || (st[i] >= '9' && st[i] <= '0')))
		return (tab);
	    }
	}
	i = i + 1;
    }
  return (tab);
}

int     nbwords(char *str)
{
  int   i;
  int   nb;

  i = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      if ((str[i] <= 'Z' && str[i] >= 'A') || (str[i] <= 'z' &&str[i] >= 'a') ||
	  (str[i] >= '9' && str[i] <= '0'))
        {
          while ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') ||
		 (str[i] >= '0' && str[i] <= '9'))
	    i = i + 1;
          nb = nb + 1;
        }
      else
	i = i + 1;
    }
  return (nb);
}

char    **my_str_to_wordtab(char *str)
{
  char  **tab;
  char	*ch;
  int	j;
  int   i;
  
  j = 0;
  i = 0;
  tab = malloc(((nbwords(str) + 1) * sizeof(char *)));
  if (tab == NULL)
    {
      my_putstr("malloc failed");
      return (NULL);
    }
  while (j != nbwords(str))
    {
      tab[j] = malloc((my_strlen(str) * sizeof(char)));
      if (tab[j] == NULL)
	{
	  my_putstr("malloc failed");
	  return (NULL);
	}
      ch = words(str, i);
      tab[j] = ch;
      i = i + my_strlen(ch) + 1;
      j = j + 1;
    }
  tab[j] = NULL;
  return (tab);
}
