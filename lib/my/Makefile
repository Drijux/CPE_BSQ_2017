##
## @Author: Drijux
## @Date:   2019-09-26 15:49:04
## @Last Modified by:   Drijux
##

AR		=	ar rc

CFLAGS	+=	-Wall -Wextra

NAME	=	libmy.a

SRC		+=	my_strcpy.c\
			my_getnbr.c\
			my_memset.c\
			my_strlen.c\
			my_strdup.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(AR) $(NAME) $(OBJ)
		cp my.h ../../include/
clean:
		rm -f $(OBJ)
fclean:	clean
		rm -f $(NAME)
re:	fclean all

.PHONY: all clean fclean re
