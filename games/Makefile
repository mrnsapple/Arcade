##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

SRC	=	game.cpp

all	:
	g++ $(SRC) -c -fpic
	g++ -shared -o lib_arcade_game.so game.o

clean	:
	rm -rf *.o

fclean	:	clean
	rm -rf *.so

re	:	fclean all