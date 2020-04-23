NAME	=	piboy

CC	=	g++

CXXFLAGS=	-W -Wall -Wextra -Iinclude -I./libs/raylib -I./libs -std=c++17 -I/usr/include/lua5.3 -g

LDFLAGS	=	-L./libs/raylib -lraylib -lX11 -ldl -lpthread -lm -lwiringPi -llua5.3 -lstdc++fs

SRCS	=	$(wildcard srcs/*.cpp)

OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
