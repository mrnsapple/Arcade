##
## EPITECH PROJECT, 2017
##
## File description:
##
##

SRC 	=	my_puts.cpp


OBJ	=	$(SRC:.c=.o)

NAME 	=	a.out

RM	=	rm -f

all:	$(NAME)


$(NAME):	#$(OBJ)
	g++ $(SRC) -c  -fpic
	g++ -shared -o liball.so *.o 
	g++ -g -Wall -Werror -Wextra main.cpp -L. -ldl #-lall
	#gcc -g -Wall -Werror -o $(NAME) $(SRC)

clean:
	$(RM) $(NAME)

fclean:	clean
	rm -f $(OBJ) $(NAME) *.so *~ *# 

re:	fclean all
