/*
** t_listInt32_remove.c for lib in /home/flavian.gontier/projects/libmy/src/list/t_listInt32
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 01:22:50 2017 flavian gontier
** Last update Mon Apr 03 14:09:53 2017 flavian gontier
*/

#include "libmy.h"

/* remove the first element encountered from the beginning */
void		listInt32_remove(t_listInt32 *list, int32_t elem)
{
  register int	index;
  int		count;

  index = 0;
  while (index < list->count)
    {
      if (list->elements[index] == elem)
	break ;
      index = index + 1;
    }
  count = (list->count - index);
  if (index != list->count - 1)
    my_memcpy(&list->elements[index], &list->elements[index + 1], count);
  list->count = list->count - 1;
}
