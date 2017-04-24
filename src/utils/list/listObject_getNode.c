/*
** listObject_getNode.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/utils
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Mon Apr 24 18:39:38 2017 flavian gontier
** Last update Mon Apr 24 18:42:30 2017 flavian gontier
*/

#include "raytracer.h"

t_node		*listObject_getNode(t_listObject *list, int64_t id)
{
  t_node	*node;

  node = list->begin;
  while (node->id != id)
  {
    if (node->next == NULL)
      return (NULL);
    node = node->next;
  }
  return (node);
}
