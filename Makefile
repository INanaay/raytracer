SRCS		= main.c

OBJS		= $(SRCS:.c=.o)

NAME		= raytracer2

RM		= rm -rf

CFLAGS		= -g3

CPPFLAGS	= -Ignl -Iinclude

all:		$(NAME)

$(NAME):	$(OBJS)
		gcc -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
