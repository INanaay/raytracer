/*
** t_listInt32_add.c for lib in /home/flavian.gontier/projects/libmy/src/list/t_listInt32
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 01:11:02 2017 flavian gontier
** Last update Mon Apr 03 14:10:27 2017 flavian gontier
*/

#include "libmy.h"

void	listInt32_add(t_listInt32 *list, int32_t elem)
{
  if (list->count == list->capacity)
    {
      listInt32_expends(list);
    }
  list->elements[list->count] = elem;
  list->count = list->count + 1;
}
