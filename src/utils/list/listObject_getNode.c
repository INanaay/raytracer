/*
** listObject_getNode.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/utils
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Mon Apr 24 18:39:38 2017 flavian gontier
** Last update Fri May 12 11:50:04 2017 NANAA
*/

#include "raytracer.h"

t_nodeObject		*listObject_getNode(t_listObject *list, int64_t id)
{
  t_nodeObject	*node;
  int		index;

  index = 0;
  node = list->begin;
  if (node == NULL)
    return (NULL);
  while (index != id)
  {
    if (node->next == NULL)
      return (NULL);
    node = node->next;
    index++;
  }
  return (node);
}
