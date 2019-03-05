##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

SRC	=	Sfml.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	lib_arcade_

SFMLFLAGS	=	-lsfml-audio	\
				-lsfml-graphics	\
				-lsfml-network	\
				-lsfml-system	\
				-lsfml-window

.cpp.o	:
	g++ $(SRC) -c -fpic

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	g++ -shared -o ../$(NAME)sfml.so Sfml.o $(SFMLFLAGS)

clean	:
	rm -rf $(OBJ)

fclean	:	clean
	rm -rf ../*.so

re	:	fclean all
