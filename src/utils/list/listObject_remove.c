/*
** listObject_remove.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/utils
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Mon Apr 24 16:50:06 2017 flavian gontier
** Last update Tue May 23 12:57:32 2017 NANAA
*/

#include "raytracer.h"

/*
void		listObject_reset_index(t_nodeObject *node)
{
  node = node->next;
  while (node != NULL)
    {
      node->id = node->id - 1;
      node = node->next;
    }
    }*/

int		listObject_remove(t_listObject *list, int64_t id)
{
  t_nodeObject	*node;

  node = listObject_getNode(list, id);
  if (node == NULL)
    return (EXIT_ERROR);
  if ((list->count = list->count - 1) >= 1)
  {
    if (node->next == NULL)
    {
      list->end = node->prev;
      node->prev->next = NULL;
    }
    else if (node->prev == NULL)
    {
      list->begin = node->next;
      node->next->prev = NULL;
    }
    else
    {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }
    //    listObject_reset_index(&(*node));
  }
  free(node);
  return (EXIT_SUCCESS);
}
