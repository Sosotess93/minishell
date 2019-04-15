/*
** prompt.c for promt in /home/charra_s/Minishell2 [Maj]
** 
** Made by Sofiane Charrad
** Login   <charra_s@epitech.net>
** 
** Started on  Sat Mar 14 13:40:22 2015 Sofiane Charrad
** Last update Sat Mar 14 14:50:30 2015 Sofiane Charrad
*/

# include "mnsh.h"

void		prompt_deux()
{
  write(1, "\033[1;33;40m", 10);
  my_putchar('[');
  write(1, g_prmt->usr_name, my_strlen(g_prmt->usr_name));
  write(1, "@", 1);
  write(1, g_prmt->pc_name, my_strlen(g_prmt->pc_name));
  my_putchar(' ');
  my_put_nbr(g_prmt->nbr_cmd_exec);
  my_putchar(']');
  write(1, "\033[0m", 4);
  my_putstr1(" ", 1);
  write(1, "\033[1;31;40m", 10);
  write(1, g_prmt->pwd, my_strlen(g_prmt->pwd));
  my_putstr1("# ", 1);
  write(1, "\033[0m", 4);
}

void		prompt_ctrl_deux()
{
  g_prmt->signal = 1;
  write(1, "\033[1;33;40m", 10);
  my_putstr1("\n[", 1);
  write(1, g_prmt->usr_name, my_strlen(g_prmt->usr_name));
  write(1, "@", 1);
  write(1, g_prmt->pc_name, my_strlen(g_prmt->pc_name));
  my_putchar(' ');
  my_put_nbr(g_prmt->nbr_cmd_exec);
  my_putchar(']');
  write(1, "\033[0m", 4);
  my_putstr1(" ", 1);
  write(1, "\033[1;31;40m", 10);
  write(1, g_prmt->pwd, my_strlen(g_prmt->pwd));
  my_putstr1("# ", 1);
  write(1, "\033[0m", 4);
}
