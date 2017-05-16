SRCS		=	src/main.c							\
		  		src/window/my_create_window.c		\
		  		src/window/my_show_window.c			\
		  		src/utils/create_vectors.c			\
				src/tracing/shadow.c				\
		  		src/gui/print_gui.c					\
		  		src/init.c							\
		  		src/tracing/utils.c					\
		  		src/gui/button_hit.c				\
		  		src/tracing/draw_objects.c			\
		  		src/gui/handle_poll_events.c			\
				src/tracing/create_object.c			\
				src/utils/list/listObject_add.c				\
				src/utils/list/listObject_getNode.c		\
				src/utils/list/listObject_init.c		\
				src/utils/list/listObject_remove.c		\
				src/tracing/sphere.c				\
				src/tracing/dir_vector.c			\
				src/tracing/normalize_vector.c			\
				src/tracing/plane.c				\
				src/tracing/cone.c				\
				src/tracing/cylinder.c				\
				src/tracing/color.c				\
				src/tracing/light.c				\
				src/gui/modify_objects.c			\
				src/gui/move_objects.c				\
				src/window/my_clear_buffer.c			\
				src/tracing/rotate.c				\
				src/tracing/translate.c				\
				src/gui/handle_movements.c			\
				src/tracing/damier.c				\
				src/gui/create_buttons.c			\
				src/gui/choose_light.c

OBJS		= 	$(SRCS:.c=.o)

NAME		= 	raytracer2

RM			= 	rm -rf

CFLAGS		= 	-O2

CPPFLAGS	= 	-Iinclude -Wall -Wextra -g3

MY_LIB		=	src/lib

all:			$(NAME)

$(MY_LIB):
		make -C lib

$(NAME):		$(OBJS)
			make -C src/lib
			gcc -o $(NAME) $(OBJS) -lc_graph_prog_full -lm libmy.a

clean:
			$(RM) $(OBJS)
			make -C src/lib clean

fclean:			clean	
			$(RM) $(NAME)
			make -C src/lib fclean

re:				fclean all

.PHONY: 		all clean fclean re
