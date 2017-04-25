/*
** listObject_getNode.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/utils
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Mon Apr 24 18:39:38 2017 flavian gontier
** Last update Tue Apr 25 12:05:05 2017 NANAA
*/

#include "raytracer.h"

t_nodeObject		*listObject_getNode(t_listObject *list, int64_t id)
{
  t_nodeObject	*node;

  node = list->begin;
  while (node->id != id)
  {
    if (node->next == NULL)
      return (NULL);
    node = node->next;
  }
  return (node);
}
