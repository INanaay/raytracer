/*
** my_strncpy.c for lib in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_navy/src/lib/string
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Fri Feb 03 12:18:49 2017 flavian gontier
** Last update Fri Feb 17 10:40:25 2017 flavian gontier
*/

#include <stdlib.h>
#include <stdint.h>

char			*my_strncpy(char *dest, char *src, size_t n)
{
  register uint32_t	counter;

  counter = 0;
  while (counter < n)
  {
    if (src[counter] == 0)
      break ;
    dest[counter] = src[counter];
    counter = counter + 1;
  }
  return (dest);
}
