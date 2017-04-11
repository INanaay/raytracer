/*
** my_realloc.c for shell in /home/flavian.gontier/Tek1/C_Prog_Elem/minishell/src
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Sat Jan 21 04:16:02 2017 flavian gontier
** Last update Sat Jan 21 21:14:44 2017 flavian gontier
*/

#include <stdlib.h>
#include "libmy.h"

void	*my_realloc(void *ptr, size_t size)
{
  void	*dest;
  int	len;

  dest = my_calloc(size);
  len = my_strlen(ptr);
  my_memcpy(dest, ptr, len);
  return (dest);
}
