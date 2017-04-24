SRCS		=	src/main.c							\
		  		src/window/my_create_window.c		\
		  		src/window/my_show_window.c			\
		  		src/utils/create_vectors.c			\
		  		src/gui/print_gui.c					\
		  		src/init.c							\
		  		src/tracing/utils.c					\
		  		src/gui/button_hit.c				\
		  		src/tracing/draw_objects.c			\
		  		src/gui/handle_poll_events.c

OBJS		= 	$(SRCS:.c=.o)

NAME		= 	raytracer2

RM			= 	rm -rf

CFLAGS		= 	-g3 -Wall -Wextra

CPPFLAGS	= 	-Iinclude

MY_LIB		=	src/lib

all:			$(NAME)

$(MY_LIB):
		make -C lib

$(NAME):		$(OBJS)
			make -C src/lib
			gcc -o $(NAME) $(OBJS) -lc_graph_prog_full libmy.a

clean:
			$(RM) $(OBJS)
			make -C src/lib clean

fclean:			clean	
			$(RM) $(NAME)
			make -C src/lib fclean

re:				fclean all

.PHONY: 		all clean fclean re
