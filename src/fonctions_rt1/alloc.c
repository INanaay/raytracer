/*
** alloc.c for  in /home/NANAA/projets/PSU_2016_minishell1
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Jan 13 16:45:54 2017 Nathan Lebon
** Last update Tue Mar 28 10:45:22 2017 NANAA
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/ray.h"

char	*my_strcat(char *dest, const char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i])
    i = i + 1;
  while (src[j])
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = 0;
  return (dest);
}

char	*my_realloc(char *str, int size)
{
  int	i;
  char	*new;

  if ((new = malloc(sizeof (char) * size + 1)) == NULL)
    return (NULL);
  if (str == NULL)
    {
      new[0] = 0;
      return (new);
    }
  i = 0;
  while (str[i])
    {
      new[i] = str[i];
      i = i + 1;
    }
  new[i] = 0;
  return (new);
}
