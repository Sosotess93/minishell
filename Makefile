##
## Makefile for  in /home/mellit_r/PSU_2014_minishell1
## 
## Made by Ramzi Melliti
## Login   <mellit_r@epitech.net>
## 
## Started on  Mon Jan 19 16:36:16 2015 Ramzi Melliti
## Last update Sun Mar 15 20:38:34 2015 Sofiane Charrad
##

NAME	= mysh

LDFLAGS =  -Wall -Werror -Wextra

LCFLAGS = -g3

SRC	= write.c \
	  path.c \
	  prompt2.c \
	  fct_sys.c \
	  fct_base.c \
	  prompt.c \
	  recup.c \
	  cat_f_shell.c \
	  my_fork.c \
	  str_to_wordtab.c \
	  fill.c \
	  for_my_setenv.c \
	  builtin.c \
	  ctrl.c \
	  check.c \
	  my_putstr2.c \
	  manip_env.c

CC	= gcc

RM	= rm -f

OBJ	= $(SRC:.c=.o)

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LCFLAGS) -o $(NAME)

clean	:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re	: fclean all

.phony	: all clean fclean re
