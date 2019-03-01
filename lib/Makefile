##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

SRC	=	Sfml.cpp

all	:
	g++ $(SRC) -c -fpic
	g++ -shared -o lib_arcade_sfml.so Sfml.o

clean	:
	rm -rf *.o

fclean	:	clean
	rm -rf *.so

re	:	fclean all
