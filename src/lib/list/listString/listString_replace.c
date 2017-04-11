/*
** listString_replace.c for lib in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_minishell2/src/lib/list/listString
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Fri Apr 07 22:46:54 2017 flavian gontier
** Last update Sat Apr 08 11:56:18 2017 flavian gontier
*/

#include "libmy.h"

int	listString_replace(t_listString *list, const char *elem, size_t index)
{
  free(list->elements[index]);
  list->elements[index] = my_strdup(elem);
  return (EXIT_SUCCESS);
}
