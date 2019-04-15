/*
** my_putstr.c for my_pustr.c in /afs/epitech.net/users/all/debas_e/rendu/pis**cine/Jour_04
**
** Made by etienne debas
** Login   <debas_e@epitech.net>
**
** Started on  Thu Oct  4 14:23:53 2012 etienne debas
** Last update Sat Mar 14 13:54:27 2015 Sofiane Charrad
*/

#include "mnsh.h"

int		my_putstr1(char *str, int fd)
{
  write(fd, str, my_strlen(str));
}

int		my_putstr2(char *str1, char *str2, int fd)
{
  my_putstr1(str1, fd);
  my_putstr1(str2, fd);
}

int		my_putstr3(char *str1, char *str2, char *str3, int fd)
{
  my_putstr1(str1, fd);
  my_putstr1(str2, fd);
  my_putstr1(str3, fd);
}
