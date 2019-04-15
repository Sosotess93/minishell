/*
** minishell.h for  in /home/mellit_r/PSU_2014_minishell1
** 
** Made by Ramzi Melliti
** Login   <mellit_r@epitech.net>
** 
** Started on  Wed Jan 21 15:22:24 2015 Ramzi Melliti
** Last update Sat Mar 14 20:17:13 2015 Sofiane Charrad
*/



#ifndef MINISHELL_H_
# define MINISHELL_H_

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <fcntl.h>

struct	s_path
{
  int	i;
  int	j;
  int	s;
  char	**izi;
  char	*str;
  char buf[4096];
};

typedef struct data_prmt
{
  char          *usr_name;
  char          *pc_name;
  int           nbr_cmd_exec;
  char          *cur_dir;
  char          *pwd;
  int           signal;
}               data_prmt;

typedef struct  s_pwd
{
  struct stat   cur;
  struct stat   par;
  struct stat   tmpbuffer;
  struct dirent *entry;
  DIR           *dir;
  int           fnd;
  int           length;
  int           length2;
  char          *res_dir;
  char          *fnd_dir;
}               t_pwd;

typedef struct  l_list
{
  char  *buff_command;
  char  **path;
  char  **env;
  char  **env_o;
  int   env_0;
  int   env_i;
  char  *path_home;
  char  *last_dir;
  char  *old_pwd;
  char  *old_pwd2;
  char  **alias;
}               t_list;


struct	s_recup
{
  char  **tab;
  char  **rec;
  char  *cat;
  int   i;
  int   c;
};

struct	s_word
{
  int   i;
  int   s;
  int   r;
};

#endif /* !MINISHELL_H_*/
