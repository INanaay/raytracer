/*
** t_listString_insert.c for lib in /home/flavian.gontier/projects/libmy/src
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 03:21:59 2017 flavian gontier
** Last update Tue Apr 04 17:15:08 2017 flavian gontier
*/

#include "libmy.h"

static char	**insert_elem(t_listString *list, const char *element,
			      size_t index)
{
  size_t	counter;
  char		**inserted;

  counter = 0;
  inserted = malloc(sizeof(char *) * list->capacity);
  if (inserted == NULL)
    return (NULL);
  while (counter < index)
  {
    inserted[counter] = list->elements[counter];
    counter += 1;
  }
  inserted[counter] = my_strdup(element);
  counter += 1;
  while (counter < list->count)
  {
    inserted[counter] = list->elements[counter - 1];
    counter += 1;
  }
  return (inserted);
}

int		listString_insert(t_listString *list, const char *elem,
				  size_t index)
{
  char		**inserted;

  if (list->count == list->capacity)
    listString_expends(list);
  inserted = insert_elem(list, elem, index);
  if (inserted == NULL)
    return (EXIT_ERROR);
  free(list->elements);
  list->elements = inserted;
  list->count = list->count + 1;
  return (EXIT_SUCCESS);
}
