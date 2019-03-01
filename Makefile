##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

SRC =	arcade.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	arcade

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	g++ -g -Wall -Werror -Wextra -o $(NAME) $(SRC) -ldl

core:
	g++ -g -Wall -Werror -Wextra -o $(NAME) $(SRC) -ldl

games:
	make -C games

graphicals:
	make -C lib

clean:
	rm -rf $(NAME)
	make -C lib clean

fclean:	clean
	rm -rf $(OBJ) $(NAME) *.so *~ *# 
	make -C lib fclean

re:	fclean all
