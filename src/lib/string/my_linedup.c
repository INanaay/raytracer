/*
** my_linedup.c for libmy in /home/flavian.gontier/C_Graphical/libmy3d/utils/string
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Wed Dec 21 23:49:53 2016 flavian gontier
** Last update Sat Jan 21 00:22:05 2017 flavian gontier
*/

#include "libmy.h"

int	my_linelen(char *str)
{
  register int	len;

  len = 0;
  while (str[len] != '\n' && str[len] != 0)
    {
      len = len + 1;
    }
  return (len);
}

char	*my_linedup(char *str)
{
  register int	index;
  char		*result;

  index = 0;
  result = my_calloc(sizeof(char) * (my_linelen(str) +  1));
  if (result == NULL)
    return (NULL);
  while (str[index] != '\n' && str[index] != 0)
    {
      result[index] = str[index];
      index = index + 1;
    }
  return (result);
}
