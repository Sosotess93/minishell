/*
** check_malloc.c for  in /home/mellit_r/PSU/PSU_2014_minishell1
** 
** Made by Ramzi Melliti
** Login   <mellit_r@epitech.net>
** 
** Started on  Thu Mar  5 16:39:25 2015 Ramzi Melliti
** Last update Fri Mar  6 18:14:39 2015 Ramzi Melliti
*/

#include "mnsh.h"

void	fill(char **myenv, struct s_path *va)
{
  while (va->s != cnt_pth(myenv[va->i]))
    {
      va->str = cut_path(myenv[va->i], va->j);
      va->izi[va->s] = va->str;
      va->j = va->j + my_strlen(va->str) + 1;
      va->s = va->s + 1;
    }
}
