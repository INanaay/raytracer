/*
** t_listString_add.c for lib in /home/flavian.gontier/projects/libmy/src/list/t_listString
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 01:11:02 2017 flavian gontier
** Last update Wed Apr 05 18:56:55 2017 flavian gontier
*/

#include "libmy.h"

int	listString_add(t_listString *list, const char *elem)
{
  int	error;

  error = 0;
  if (list->count == list->capacity)
    {
      error = listString_expends(list);
    }
  if (error)
    return (EXIT_ERROR);
  list->elements[list->count] = my_strdup(elem);
  list->count = list->count + 1;
  return (EXIT_SUCCESS);
}
