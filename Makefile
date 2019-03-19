##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

SRC =	arcade.cpp

LIBSRC	=	sfml/Sfml.cpp opengl/OpenGL.cpp ncurses/NCurses.cpp ncurses/NCurses_pacman_only.cpp

GAMESSRC	=	nibbler/Nibbler.cpp	\
				pacman/Pacman.cpp

OBJ	=	$(SRC:.cpp=.o)

LIBOBJ	=	$(LIBSRC:.cpp=.o)

GAMESOBJ	=	$(GAMESSRC:.cpp=.o)

SFMLFLAGS	=	-lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio -lsfml-network

OPENGLFLAGS =	-lSDL2 -lGLEW -lGL

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
	mkdir -p games
	g++ -shared -o games/lib_arcade_nibbler.so Nibbler.o $(SFMLFLAGS)
	g++ -shared -o games/lib_arcade_pacman.so Pacman.o $(SFMLFLAGS)

graphicals	:	$(LIBOBJ)
	mkdir -p lib
	g++ -shared -o lib/lib_arcade_sfml.so Sfml.o $(SFMLFLAGS)
	g++ -shared -o lib/lib_arcade_opengl.so OpenGL.o $(OPENGLFLAGS)
	g++ -shared -o lib/lib_arcade_ncurses.so NCurses.o NCurses_pacman_only.o -lncurses

clean:
	rm -rf $(LIBOBJ)
	rm -rf $(GAMESOBJ)
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME) *~ *# *.o
	rm -rf lib/*.so
	rm -rf games/*.so

re:	fclean all
