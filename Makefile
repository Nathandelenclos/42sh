##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC =	usefull_fonctions.c		\
		str_fonctions.c			\
		dbl_tab_fonctions.c		\
		env.c					\
		cd.c					\
		cd2.c					\
		exit.c					\
		setenv.c				\
		setenv2.c				\
		unsetenv.c				\
		execve.c				\
		execve2.c				\
		main.c					\
		pipe_redirect.c			\
		pipe_redirect2.c		\

OBJ =	$(SRC:.c=.o)

NAME	=	mysh

CC	=	gcc

CFLAGS	+=	-Wall -Wextra -I include/

all:	$(NAME)

$(NAME):    $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

debug:	CFLAGS += -g
debug:	fclean all

clean:
	rm -f $(OBJ)
	rm -f vgcore*

fclean: clean
	rm -f $(NAME)

re: clean all
