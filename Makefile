##
## @Author: Drijux
## @Date:   2019-09-26 15:49:04
## @Last Modified by:   Drijux
##

NAME		=	bsq

CC			= 	gcc

SRC			+=	src/main.c

CPPFLAGS	+=	-I./include

CFLAGS		+=	-Wall -Wextra

OBJ			=	$(SRC:.c=.o)

LDFLAGS		+=	-L./lib/my -lmy


all:		$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
