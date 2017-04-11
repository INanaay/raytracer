/*
** my_tabcpy.c for lib in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_tetris/src/lib/string
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Sun Mar 12 17:35:50 2017 flavian gontier
** Last update Sun Mar 12 19:14:58 2017 flavian gontier
*/

#include <stdlib.h>

void	my_tabncpy(char **dest, char **src, size_t n)
{
  register size_t	index;

  index = 0;
  while (index < n)
  {
    dest[index] = src[index];
    index = index + 1;
  }
}
