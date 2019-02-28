##
## EPITECH PROJECT, 2017
##
## File description:
##
##

SRC 	=	my_puts.c


OBJ	=	$(SRC:.c=.o)

NAME 	=	a.out

RM	=	rm -f

all:	$(NAME)


$(NAME):	#$(OBJ)
	gcc $(SRC) -c  -fpic
	gcc -shared -o liball.so *.o 
	gcc -g -Wall -Werror -Wextra main.c -L. -ldl #-lall
	#gcc -g -Wall -Werror -o $(NAME) $(SRC)

clean:
	$(RM) $(NAME)

fclean:	clean
	rm -f $(OBJ) $(NAME) *.so *~ *# 

re:	fclean all
