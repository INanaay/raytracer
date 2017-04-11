/*
** t_listInt32_expends.c for lib in /home/flavian.gontier/projects/libmy/src/list/t_listInt32
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 02:45:03 2017 flavian gontier
** Last update Mon Apr 03 14:09:17 2017 flavian gontier
*/

#include "libmy.h"

void		listInt32_expends(t_listInt32 *list)
{
  int32_t	*new;

  new = malloc(sizeof(int32_t) * (list->capacity * 2));
  my_memcpy(new, list->elements, list->count * sizeof(int32_t));
  free(list->elements);
  list->elements = new;
  list->capacity = list->capacity * 2;
}
