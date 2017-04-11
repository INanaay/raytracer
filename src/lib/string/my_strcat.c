/*
** my_strcat.c for lib in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_minishell1/lib/string
**
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
**
** Started on  Fri Jan 13 18:40:18 2017 flavian gontier
** Last update Mon Mar 20 17:20:45 2017 nathan
*/

#include <unistd.h>

char		*my_strcat(char *dest, char *src)
{
  register int	index;

  index = 0;
  if (src == NULL)
    return (dest);
  while (dest[index] != 0)
    {
      index = index + 1;
    }
  while (*src != 0)
    {
      dest[index] = *src;
      index = index + 1;
      src = src + 1;
    }
  dest[index] = 0;
  return (dest);
}
