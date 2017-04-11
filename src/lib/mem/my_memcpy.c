/*
** my_memcpy.c for libmy in /home/flavian.gontier/C_Graphical/libmy3d/src/utils/mem
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Tue Jan  3 22:35:35 2017 flavian gontier
** Last update Thu Feb 02 10:12:22 2017 flavian gontier
*/

#include <stdlib.h>

void		*my_memcpy(void	*destination, void *source, size_t n)
{
  char		*src;
  char		*dest;
  register uint	index;

  src = (char *)source;
  dest = (char *)destination;
  index = 0;
  while (index < n)
    {
      dest[index] = src[index];
      index = index + 1;
    }
  return (dest);
}
