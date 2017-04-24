/*
** listObject_remove.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/utils
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Mon Apr 24 16:50:06 2017 flavian gontier
** Last update Mon Apr 24 18:44:28 2017 flavian gontier
*/

#include "raytracer.h"

int		listObject_remove(t_listObject *list, t_object *object)
{
  t_node	*node;

  node = listObject_getNode(list, object);
  if (node == NULL)
    return (EXIT_ERROR);
  if (list->length-- != 1)
  {
    if (node->next == NULL)
    {
      list->end = node->prev;
      node->prev->next == NULL;
    }
    else if (node->prev == NULL)
    {
      list->begin = node->next;
      node->next->prev == NULL;
    }
    else
    {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }
  }
  free(node);
  return (EXIT_SUCCESS);
}
