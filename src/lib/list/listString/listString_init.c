/*
** t_listString_init.c for lib in /home/flavian.gontier/projects/libmy/src/list/t_listString
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Fri Jan 27 00:54:56 2017 flavian gontier
** Last update Sun Apr 09 00:27:21 2017 flavian gontier
*/

#include "libmy.h"

int	listString_init(t_listString *list)
{
  if (list == NULL)
    {
      return (EXIT_ERROR);
    }
  list->count = 0;
  list->elements = my_calloc(sizeof(char *) * LIST_DEFAULT_CAPACITY);
  if (list->elements == NULL)
  {
    return (EXIT_ERROR);
  }
  list->capacity = LIST_DEFAULT_CAPACITY;
  return (EXIT_SUCCESS);
}
