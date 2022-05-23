##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

MAIN =	main.c	\

SRC_PATH = src/

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
		pipe_redirect.c			\
		pipe_redirect2.c		\

FILES = $(addprefix $(SRC_PATH), $(SRC))	\
		$(addprefix $(SRC_PATH), $(MAIN))

TEST_FILE	=	tests/cd_tests.c	\
				tests/usefull_functions.c	\
				tests/str_functions.c	\

OBJ =	$(FILES:.c=.o)

NAME	=	42sh

CC	=	gcc

LIB	=	-llist	\
		-lmy

CFLAGS	+=	-Wall -Wextra -I include/ -L./lib $(LIB)

all:	buildlib $(NAME)

debug:	CFLAGS += -g
debug:	fclean all

clean:
	rm -f $(OBJ)
	rm -f vgcore*

fclean: clean
	rm -f $(NAME)
	make -C ./lib/my/ fclean
	make -C ./lib/linked_list/ fclean

buildlib:
	make -C ./lib/my/
	make -C ./lib/linked_list/

tests_run:
	gcc -o unit_tests $(SRC) $(TEST_FILE) --coverage -lcriterion
	./unit_tests
	gcovr -r .
	rm -f unit_tests*

re: fclean all

$(NAME):    $(OBJ)
	$(CC) -o $(NAME) $(OBJ)