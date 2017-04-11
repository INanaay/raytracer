/*
** t_listString_remove.c for lib in /home/flavian.gontier/projects/libmy/src/list/t_listString
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 01:22:50 2017 flavian gontier
** Last update Sun Apr 09 13:49:01 2017 flavian gontier
*/

#include "libmy.h"

static void	shift_elements(t_listString *list, int start_index)
{
  int		index;
  int		limit;

  index = start_index;
  limit = (int)(list->count - 1);
  while (index < limit)
  {
    list->elements[index] = list->elements[index + 1];
    index = index + 1;
  }
}

int		listString_removeIndex(t_listString *list, size_t index)
{
  if (index >= list->count)
    return (EXIT_ERROR);
  free(list->elements[index]);
  shift_elements(list, index);
  list->count -= 1;
  return (EXIT_SUCCESS);
}

/*
** remove the first element encountered from the beginning
*/
int		listString_remove(t_listString *list, const char *elem)
{
  int		index;

  if (list == NULL || elem == NULL || list->count == 0)
    return (EXIT_ERROR);
  index = listString_contains(list, elem);
  if (index == -1)
    return (EXIT_ERROR);
  listString_removeIndex(list, index);
  return (EXIT_SUCCESS);
}
