/*
** t_listString_expends.c for lib in /home/flavian.gontier/projects/libmy/src/list/t_listString
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 02:45:03 2017 flavian gontier
** Last update Sun Apr 09 00:27:06 2017 flavian gontier
*/

#include "libmy.h"

int		listString_expends(t_listString *list)
{
  char		**new;

  new = my_calloc(sizeof(char *) * (list->capacity * 2));
  if (new == NULL)
    return (EXIT_ERROR);
  my_memcpy(new, list->elements, list->count * sizeof(char *));
  free(list->elements);
  list->elements = new;
  list->capacity = list->capacity * 2;
  return (EXIT_SUCCESS);
}
