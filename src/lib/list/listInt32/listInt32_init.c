/*
** t_listInt32_init.c for lib in /home/flavian.gontier/projects/libmy/src/list/t_listInt32
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 00:54:56 2017 flavian gontier
** Last update Mon Apr 03 14:13:23 2017 flavian gontier
*/

#include "libmy.h"

void	listInt32_init(t_listInt32 *list)
{
  if (list == NULL)
    {
      return ;
    }
  list->count = 0;
  list->elements = malloc(sizeof(int32_t) * (LIST_DEFAULT_CAPACITY + 1));
  list->capacity = LIST_DEFAULT_CAPACITY;
  if (list->elements == NULL)
    {
      return ;
    }
}
