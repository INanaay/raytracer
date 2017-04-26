CC		=	gcc

LINKDIR	=	../../include

CFLAGS	+=	-Wall -Wextra -Werror -I$(LINKDIR)

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

CPPFLAGS = -I../../Iinclude

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rc $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
