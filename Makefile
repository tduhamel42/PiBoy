NAME	=	piboy

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -Iinclude -Ilibs/raylib

LDFLAGS	=	-L./libs/raylib -lraylib

SRCS	=	$(wildcard srcs/*.c)

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
