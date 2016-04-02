##
## Makefile for C:\Users\Julien\Desktop\rendu in C:\Users\Julien\Desktop\rendu\prog_elem_s2\CPE_2015_Allum1
##
## Made by Julien Leleu
## Login   <Julien@epitech.net>
##
## Started on  Tue Feb 09 16:53:15 2016 Julien Leleu
## Last update Tue Feb 09 16:53:15 2016 Julien Leleu
##

NAME	= allum1

SRC	= allum1.c \
	  board_actions.c \
	  check_functions.c \
	  functions.c \
	  player.c \
	  ia.c

FLAGS	= -W -Wall -ansi -pedantic -Wextra

all: $(NAME)


$(NAME):
	gcc -o $(NAME) $(SRC) -I./ $(FLAGS)

clean:
	rm -rf *~

fclean: clean
	rm -rf $(NAME)

re: fclean all
