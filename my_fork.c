/*
** my_fork.c for  in /home/mellit_r/PSU_2014_minishell1
** 
** Made by Ramzi Melliti
** Login   <mellit_r@epitech.net>
** 
** Started on  Sun Feb  1 18:24:37 2015 Ramzi Melliti
** Last update Tue Mar 10 00:03:21 2015 Ramzi Melliti
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mnsh.h"

int	go_fork(char *cat, char **rec, char **env)
{
  pid_t	pid;
  int	i;

  pid = fork();
  if (pid == -1)
    {
      my_putstr("fork failed\n");
      return (1);
    }
  if (pid == 0)
    {
      pid = getpid();
      i = execve(cat, rec, env);
      if (i == -1)
	{
	  my_putstr("execution failed\n");
	  return (1);
	}
    }
  else
    wait(&pid);
  return (0);
}
