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
	@$(MAKE) core --no-print-directory
	@$(MAKE) graphicals --no-print-directory

core:
	g++ -g -Wall -Werror -Wextra -o $(NAME) $(SRC) -ldl

games:
	make -C games/src --no-print-directory

graphicals:
	make -C lib/src --no-print-directory

clean:
	rm -rf $(NAME)
	make -C lib/src clean --no-print-directory

fclean:	clean
	rm -rf $(OBJ) *.so *~ *# 
	make -C lib/src fclean --no-print-directory

re:	fclean all
