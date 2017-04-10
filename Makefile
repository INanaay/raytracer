SRCS		= src/main.c				\
		  src/window/my_create_framebuffer.c	\
		  src/window/my_create_window.c		\
		  src/window/my_put_pixel.c		\
		  src/window/my_show_window.c

OBJS		= $(SRCS:.c=.o)

NAME		= raytracer2

RM		= rm -rf

CFLAGS		= -g3

CPPFLAGS	= -Iinclude

all:		$(NAME)

$(NAME):	$(OBJS)
		gcc -o $(NAME) $(OBJS) -lc_graph_prog_full

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
