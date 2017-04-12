/*
** my_memset.c for libmy in /home/flavian.gontier/C_Graphical/lib
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Thu Dec 22 00:26:31 2016 flavian gontier
** Last update Tue Apr 11 15:57:58 2017 NANAA
*/

#include "raytracer.h"

void	*my_memset(char *ptr, int len, int value)
{
  register int	index;

  index = 0;
  while (index < len)
    {
      ptr[index] = value;
      index = index + 1;
    }
  return (ptr);
}
