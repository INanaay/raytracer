/*
** my_freetab.c for shell in /home/flavian.gontier/Tek1/C_Prog_Elem/minishell
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Sat Jan 21 14:12:37 2017 flavian gontier
** Last update Sat Apr 08 12:42:13 2017 flavian gontier
*/

#include <stdlib.h>

void		my_freetab(char **tab)
{
  size_t	index;
  char		*ptr;

  index = 0;
  while (tab[index] != 0)
    {
      ptr = tab[index];
      free(ptr);
      index = index + 1;
    }
  free(tab);
}
