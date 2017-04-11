/*
** t_listInt32_insert.c for lib in /home/flavian.gontier/projects/libmy/src
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 03:21:59 2017 flavian gontier
** Last update Mon Apr 03 14:10:36 2017 flavian gontier
*/

#include "libmy.h"

void	listInt32_insert(t_listInt32 *list, int32_t elem, size_t index)
{
  int32_t	*new;

  if (list->count == list->capacity)
    listInt32_expends(list);
  new = malloc(sizeof(int32_t) * list->capacity);
  my_memcpy(new, list->elements, index);
  new[index] = elem;
  my_memcpy(&new[index + 1], &list->elements[index], list->count - index);
  free(list->elements);
  list->elements = new;
  list->count = list->count + 1;
}
