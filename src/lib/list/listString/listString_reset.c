/*
** listString_reset.c for lib in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_minishell2/src/lib/list/listString
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Sat Apr 08 13:58:56 2017 flavian gontier
** Last update Sat Apr 08 14:02:38 2017 flavian gontier
*/

#include "libmy.h"

int		listString_reset(t_listString *list)
{
  size_t	index;
  char		*element;

  index = 0;
  while (index < list->count)
  {
    element = list->elements[index];
    free(element);
    index += 1;
    list->count -= 1;
  }
  return (EXIT_SUCCESS);
}
