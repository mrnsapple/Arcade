##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

SRC =	arcade.cpp

LIBSRC	=	Sfml.cpp

GAMESSRC	=	Nibbler.cpp

OBJ	=	$(SRC:.cpp=.o)

LIBOBJ	=	$(LIBSRC:.cpp=.o)

GAMESOBJ	=	$(GAMESSRC:.cpp=.o)

SFMLFLAGS	=	-lsfml-graphics	\
				-lsfml-system	\
				-lsfml-window	\
				-lsfml-audio	\
				-lsfml-network

NAME	=	arcade

all	:	$(NAME)

$(NAME)	:
	@$(MAKE) core --no-print-directory
	@$(MAKE) games --no-print-directory
	@$(MAKE) graphicals	--no-print-directory

$(LIBSRC:.cpp=.o)	:
	g++ $(LIBSRC) -c -fpic 

$(GAMESSRC:.cpp=.o)	:
	g++ $(GAMESSRC) -c -fpic

core	:	$(OBJ)
	g++ -g -Wall -Werror -Wextra -o $(NAME) $(SRC) -ldl

games	:	$(GAMESOBJ)
	g++ -shared -o games/lib_arcade_nibbler.so Nibbler.o $(SFMLFLAGS)

graphicals	:	$(LIBOBJ)
	g++ -shared -o lib/lib_arcade_sfml.so Sfml.o $(SFMLFLAGS)

clean:
	rm -rf $(LIBOBJ)
	rm -rf $(GAMESOBJ)
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME) *~ *#
	rm -rf lib/*.so
	rm -rf games/*.so

re:	fclean all
