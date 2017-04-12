/*
** my_calloc.c for libmy in /home/flavian.gontier/C_Graphical/libmy3d/utils
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Wed Dec 21 16:12:41 2016 flavian gontier
** Last update Tue Apr 11 15:57:29 2017 NANAA
*/

#include <stdlib.h>
#include <stddef.h>
#include "raytracer.h"

void		*my_calloc(size_t len)
{
  void		*result;

  if (len == 0)
    return (NULL);
  result = malloc(len);
  if (result == NULL)
    return (NULL);
  my_memset(result, len, 0);
  return (result);
}
