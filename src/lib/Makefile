##
## Makefile for shell in /home/flavian.gontier/Tek1/C_Prog_Elem/minishell
##
## Made by flavian gontier
## Login   <flavian.gontier@epitech.net>
##
## Started on  Sat Jan 21 00:04:28 2017 flavian gontier
## Last update Sun Apr 09 22:11:00 2017 flavian gontier
##

CC		=	gcc

LINKDIR	=	../../inc

CFLAGS	+=	-Wall -Wextra -Werror -g3 -I$(LINKDIR)

CPPFLAGS +=

SRC		=	io/my_put.c									\
			io/my_putstr.c								\
			io/my_puterr.c								\
			io/get_next_line.c							\
			mem/my_calloc.c								\
			mem/my_realloc.c							\
			mem/my_memset.c								\
			mem/my_memcpy.c								\
			mem/my_freetab.c							\
			string/my_atoi.c							\
			string/my_linedup.c							\
			string/my_strncmp.c							\
			string/my_strcmp.c							\
			string/my_strcat.c							\
			string/my_strcpy.c							\
			string/my_strncpy.c							\
			string/my_strindex.c						\
			string/my_strsplit.c						\
			string/my_strcontains.c						\
			string/my_strisalphanum.c					\
			string/my_strdup.c							\
			string/my_strndup.c							\
			string/my_len.c								\
			string/my_strlen.c							\
			string/my_strtab.c							\
			string/my_tablen.c							\
			string/my_tabncpy.c							\
			list/listInt32/listInt32_add.c				\
			list/listInt32/listInt32_remove.c			\
			list/listInt32/listInt32_insert.c			\
			list/listInt32/listInt32_init.c				\
			list/listInt32/listInt32_expends.c			\
			list/listString/listString_add.c			\
			list/listString/listString_remove.c			\
			list/listString/listString_reset.c			\
			list/listString/listString_insert.c			\
			list/listString/listString_init.c			\
			list/listString/listString_contains.c		\
			list/listString/listString_replace.c		\
			list/listString/listString_expends.c

OBJS	=		$(SRC:.c=.o)

RM      =       rm -rf

NAME    =     	../../libmy.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rc $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
