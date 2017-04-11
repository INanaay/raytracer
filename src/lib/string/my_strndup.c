/*
** my_strndup.c for lib in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_tetris/src/lib/string
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 15 14:39:04 2017 flavian gontier
** Last update Wed Mar 15 18:19:17 2017 flavian gontier
*/

#include <stdlib.h>

char	*my_strndup(char *str, size_t n)
{
  char		*result;
  size_t	index;

  index = 0;
  result = malloc(sizeof(char) * (n + 1));
  if (result == NULL)
    return (NULL);
  while (str[index] != 0 && index < n)
  {
    result[index] = str[index];
    index = index + 1;
  }
  result[index] = 0;
  return (result);
}
