/*
** path.c for  in /home/mellit_r/PSU_2014_minishell1
** 
** Made by Ramzi Melliti
** Login   <mellit_r@epitech.net>
** 
** Started on  Sun Jan 25 17:34:30 2015 Ramzi Melliti
** Last update Sun Mar 15 21:51:57 2015 Sofiane Charrad
*/

#include "mnsh.h"

char    *cut_path(char *str, int i)
{
  char  *tab;
  int   j;

  j = 0;
  tab = malloc(((my_strlen(str)) * sizeof(char)));
  if (tab == NULL)
    {
      my_putstr("malloc failed");
      return (NULL);
    }
  while (str[i] != '\0')
    {
      while (str[i] != ':')
	{
	  tab[j] = str[i];
	  i = i + 1;
	  j = j + 1;
	  if (str[i] == ':' || str[i] == '\0')
	    {
	      tab[j] = '\0';
	      return (tab);
	    }
	}
    }
  return (tab);
}

int    cnt_pth(char *str)
{
  int	nb;
  int   i;

  i = 0;
  nb = 1;
  while (str[i] != '\0')
    {
      if (str[i] == ':')
	nb = nb + 1;
      i = i + 1;
    }
  return (nb);
}

char	**path(char **myenv, struct s_path *va)	
{
  va->i = 0;
  va->j = 5;
  va->s = 0;
  while (myenv[va->i] != 0)
    {
      if (myenv[va->i][0] == 'P' && myenv[va->i][1] == 'A' && myenv[va->i][2]
	  == 'T' && myenv[va->i][3] == 'H' && myenv[va->i][4] == '=')
	{
	  if ((va->izi =
	       malloc(sizeof(struct s_path) * (cnt_pth(myenv[va->i])) + 1)) == NULL)
	    {
	      my_putstr("malloc failed");
	      return (NULL);
	      }
	  fill(myenv, va);
	}
      va->i = va->i + 1;
    }
  va->izi[va->s] = NULL;
  return (va->izi);
}

/* void	ctrl_d() */
/* { */
/*   my_putchar('\n'); */
/*   exit(1); */
/* } */

/* void	ctrl_c() */
/* { */
/*   my_putstr("\n$>"); */
/* } */

int		main(int ac, char **av, char **env)
{
  struct s_path	*va;
  char		**lib;
  char		**myenv;
  data_prmt	t;

  (void)ac;
  (void)av;

  //t.pwd = my_getpwd();
  //  printf("%s\n", t.pwd);
  if ((myenv = manip_env(env, myenv)) == NULL)
    return (1);
  if ((va = malloc(sizeof(struct s_path) + 1)) == NULL)
      {
      	my_putstr("Malloc failed.");
      	return (1);
      }
  my_putstr("No built-in in this shell.\n");
  if (path(myenv, va) == NULL)
    return (0);
  control();
  /* signal(SIGINT, ctrl_c); */
  /* signal(SIGSEGV, ctrl_d); */
  if (minishell(myenv) == 1)
    {
      my_putchar('\n');
      return (1);
    }
  lib = path(myenv, va);
  free(va->izi);
  return (0);
}
