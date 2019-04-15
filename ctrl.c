/*
** ctrl.c for  in /home/mellit_r/PSU/PSU_2014_minishell1
** 
** Made by Ramzi Melliti
** Login   <mellit_r@epitech.net>
** 
** Started on  Fri Mar 13 16:32:33 2015 Ramzi Melliti
** Last update Fri Mar 13 16:46:17 2015 Ramzi Melliti
*/

#include "mnsh.h"

void    ctrl_d()
{
  my_putchar('\n');
  exit(1);
}

void    ctrl_c()
{
  my_putstr("\n$>");
}

void	control()
{
  signal(SIGINT, ctrl_c);
  signal(SIGSEGV, ctrl_d);
}
