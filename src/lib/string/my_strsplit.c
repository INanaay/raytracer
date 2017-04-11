/*
** my_strsplit.c for lib in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_tetris/src/lib/string
**
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
**
** Started on  Tue Mar 14 12:27:21 2017 flavian gontier
** Last update Sat Apr 08 12:38:40 2017 flavian gontier
*/

#include "libmy.h"
#include <stdio.h>

static int	element_count(char *str, char c)
{
  register int	index;
  int		length;
  int		count;

  index = 0;
  count = 0;
  while (*str == c)
    str++;
  length = my_strlen(str);
  while (str[length - 1] == c)
    str[--length] = 0;
  while (str[index] != 0)
  {
    if (str[index] == c && str[index + 1] == 0)
      break ;
    if (str[index] == c && str[index + 1] != c && str[index + 1] != 0)
      count = count + 1;
    index = index + 1;
  }
  return (count + 1);
}

static char	*skip(char *str, char c)
{
  int		index;

  index = 0;
  while (str[index] == c)
  {
    index += 1;
  }
  return (str + index);
}

static void	split(char *str, char c, char **tab)
{
  int		line;
  int		len;

  line = 0;
  str = skip(str, c);
  while (*str != 0)
  {
    len = my_len(str, c);
    if (len == 0)
      break ;
    tab[line] = my_strndup(str, len);
    str += len;
    str = skip(str, c);
    line += 1;
  }
  tab[line] = 0;
}

char		**my_strsplit(const char *str, char c)
{
  char		*tmp;
  char		**result;
  int		size;

  tmp = my_strdup(str);
  size = element_count(tmp, c);
  result = my_calloc(sizeof(char *) * (size + 1));
  split(tmp, c, result);
  free(tmp);
  return (result);
}
