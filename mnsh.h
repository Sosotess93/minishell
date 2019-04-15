/*
** mnsh.h for  in /home/mellit_r/PSU_2014_minishell1
** 
** Made by Ramzi Melliti
** Login   <mellit_r@epitech.net>
** 
** Started on  Mon Jan 26 13:54:22 2015 Ramzi Melliti
** Last update Sat Mar 14 20:40:38 2015 Sofiane Charrad
*/

#ifndef MNSH_H_
#define MNSH_H_

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

// ecriture
int	my_strlen(char *str);
int	my_putnbr(int nb);
void	my_putchar(char c);
void	my_putstr(char *str);

data_prmt       *g_prmt;

int		my_putstr1(char *str, int fd);
int		my_putstr2(char *str1, char *str2, int fd);
int		my_putstr3(char *str1, char *str2, char *str3, int fd);
char    *my_strdup(char *src);
char    *my_strcat(char *dest, char *src);

// path
char	**path(char **env, struct s_path *var);
void	fill(char **env,struct s_path *va);
char    *cut_path(char *str, int i);

//control
void	control();

// env
char	**cpy_env(char **env, char **my_env);
char	**manip_env(char **env, char **my_env);
int	check_env(char **env);

// parsing
char	*words(char *str, int i);
char	*cat_f_shell(char *dest, char *src);
char	**my_str_to_wordtab(char *str);
int	nbwords(char *str);

// shell
int	recup(char *cat, char **env);
int	minishell(char **env);
int     go_fork(char *cat, char **rec, char **env);

//built_in
int	is_builtin(char **my_env, char *str);
int	count_env(char **my_env);
char	*new_line_env(char *str, int i);

//control
int	check(int ret);
int	check_accuss(int c);

//pwd
char		*my_getpwd();
int		init_sct(t_pwd *sct);
int		check_pwd(t_pwd *sct);
int		recursif(t_pwd *sct);

//cd
int             special_case(char **argv);
int             change_dir(char **argv);
void            change_dir_2(char **av);


#endif /* !MNSH_H_ */

