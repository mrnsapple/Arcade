##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

SRC	=	Game.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	lib_arcade_

.cpp.o	:
	g++ $(SRC) -c -fpic

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	g++ -shared -o ../$(name)game.so Game.o

clean	:
	rm -rf $(OBJ)

fclean	:	clean
	rm -rf ../*.so

re	:	fclean all
