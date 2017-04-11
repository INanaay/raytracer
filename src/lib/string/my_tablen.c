/*
** my_tablen.c for lib in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_minishell2/src/lib/string
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Fri Apr 07 21:58:29 2017 flavian gontier
** Last update Sat Apr 08 12:27:11 2017 flavian gontier
*/

#include "libmy.h"

size_t		my_tablen(char **tab)
{
  size_t	length;

  length = 0;
  while (tab[length] != 0)
  {
    length += 1;
  }
  return (length);
}
