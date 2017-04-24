/*
** libmy.h for shell in /home/flavian.gontier/Tek1/C_Prog_Elem/minishell
**
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
**
** Started on  Fri Jan 20 20:32:15 2017 flavian gontier
** Last update Mon Apr 24 15:58:40 2017 flavian gontier
*/

#ifndef LIBMY_H_
#define LIBMY_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

# define EXIT_SUCCESS 0
# define EXIT_ERROR 1
# define READ_SIZE 512

# define my_isup(x)		(x >= 'A' && x <= 'Z')
# define my_islow(x)		(x >= 'a' && x <= 'z')
# define my_isalpha(x)		(my_islow(x) || my_isup(x))
# define my_isnum(x)		(x >= '0' && x <= '9')
# define my_isalphanum(x)	(my_isalpha(x) || my_isnum(x))
# define is_equal(x, y)		(my_strcmp(x, y) == 0)
/*
** string
*/
int			my_strisalphanum(char *str);
int                     my_strcontains(char *str, char c);
int			my_strisnum(char *str);
int			my_len(char *str, char c);
int                     my_strlen(const char *str);
int			my_atoi(char *str);
char			*my_strcpy(char *dest, char *src);
int			my_strcat(char *dest, char *src);
char			*my_strncpy(char *dest, char *src, size_t n);
int			my_strindex(char *str, char c);
int			my_strcmp(const char *s1, const char *s2);
int			my_strncmp(const char *s1, const char *s2, int n);
char                    *my_strdup(const char *str);
char			*my_strndup(char *str, size_t n);
char			*my_tabelem(char **, char *name);
char                    *my_linedup(char *str);
char			**my_strsplit(const char *str, char c);
size_t			my_tablen(char **tab);

/*
** memory
*/
void                    *my_calloc(size_t size);
void			*my_realloc(void *ptr, size_t size);
void                    *my_memset(char *ptr, int len, int value);
void			*my_memcpy(void *src, void *dest, size_t len);
void			my_freetab(char **tab);

/*
** input / ouput
*/
char			*get_next_line(int fd);
char			*my_read_file(char *file);
void                    my_put(int fd, char *str);
void			my_putchar(char c);
void                    my_puterr(char *str);
void                    my_putstr(char *str);
void			my_putnbr(int nb);


/*
** list
*/

# define LIST_DEFAULT_CAPACITY 4

typedef struct	s_listInt32
{
  int32_t	count;
  int32_t	*elements;
  int32_t	capacity;
}		t_listInt32;

typedef struct	s_listString
{
  char		**elements;
  size_t	capacity;
  size_t	count;
}		t_listString;


/*
** listInt32
*/
void		listInt32_init(t_listInt32 *list);
void		listInt32_add(t_listInt32 *list, int32_t elem);
void		listInt32_expends(t_listInt32 *list);
void		listInt32_remove(t_listInt32 *list, int32_t elem);
void		listInt32_insert(t_listInt32 *list, int32_t elem, size_t index);

/*
** listString
*/
int		listString_init(t_listString *list);
int		listString_add(t_listString *list, const char *element);
int		listString_expends(t_listString *list);
int		listString_remove(t_listString *list, const char *element);
int		listString_removeIndex(t_listString *list, size_t index);
int		listString_insert(t_listString *list, const char *element,
				  size_t index);
int		listString_contains(t_listString *list, const char *element);
int		listString_replace(t_listString *list, const char *element,
				   size_t index);
int		listString_reset(t_listString *list);

#endif
