/*
** my_nstrcmp.c for Project-Master in /home/NANAA/Projets/Corewar/asm
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Wed Mar 15 13:37:49 2017 NANAA
** Last update Tue Mar 28 11:40:02 2017 NANAA
*/

#include <stdlib.h>
#include "include/ray.h"

int		my_nstrcmp(const char *s1, const char *s2, size_t n)
{
  size_t	i;

  i = 0;
  while (s1[i] && s2[i])
    {
      if (i + 1 < n && s1[i] == s2[i])
	i++;
      else
	break ;
    }
  return (s1[i] - s2[i]);
}
