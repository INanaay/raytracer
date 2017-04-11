/*
** my_strisnum.c for corewar in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2016_corewar/src/vm/lib/string
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 24 16:42:10 2017 flavian gontier
** Last update Fri Mar 24 16:52:03 2017 flavian gontier
*/

#include "libmy.h"

int	my_strisnum(char *str)
{
  register int	index;

  while (str[index] != 0)
  {
    if (my_isnum(str[index]) == 0)
      return (0);
    index = index + 1;
  }
  return (1);
}
