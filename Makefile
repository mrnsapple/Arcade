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
	make -C games --no-print-directory

graphicals:
	make -C lib --no-print-directory

clean:
	rm -rf $(NAME)
	make -C lib clean --no-print-directory

fclean:	clean
	rm -rf $(OBJ) *.so *~ *# 
	make -C lib fclean --no-print-directory

re:	fclean all
