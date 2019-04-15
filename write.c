/*
** write.c for  in /home/mellit_r/PSU_2014_minishell1
** 
** Made by Ramzi Melliti
** Login   <mellit_r@epitech.net>
** 
** Started on  Wed Jan 21 13:22:13 2015 Ramzi Melliti
** Last update Mon Mar  2 12:12:35 2015 Ramzi Melliti
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void    my_put_nbr(int nb)
{
  int   div;

  div = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
    }
  while ((nb / div ) >= 10)
    div = div * 10;
  while (div > 0)
    {
      my_putchar((nb / div ) % 10 + '0');
      div = div / 10;
    }
}

