/*
** check.c for  in /home/mellit_r/PSU/PSU_2014_minishell1
** 
** Made by Ramzi Melliti
** Login   <mellit_r@epitech.net>
** 
** Started on  Fri Mar 13 16:55:01 2015 Ramzi Melliti
** Last update Fri Mar 13 17:30:29 2015 Ramzi Melliti
*/

#include "mnsh.h"

int	check(int ret)
{
  if (ret == -1)
    {
      my_putstr("Read failed");
      return (1);
    }
  return (0);
}

int	check_access(int c)
{
  if (c == -1)
    {
      my_putstr("command does not exist\n");
      return (0);
    }
  return (0);
}
