##
## Makefile for  in /home/anatole.zeyen/raytracer2/src/utils
## 
## Made by anatole zeyen
## Login   <anatole.zeyen@epitech.net>
## 
## Started on  Tue Apr 11 14:26:12 2017 anatole zeyen
## Last update Tue Apr 11 14:56:32 2017 anatole zeyen
##

SRCS		= src/main.c				\
		  src/init.c				\
		  src/utils/create_vectors.c		\
		  src/gui/print_gui.c			\
		  src/window/my_create_window.c		\
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
