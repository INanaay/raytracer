/*
** listObject_add.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/utils
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Mon Apr 24 16:31:24 2017 flavian gontier
** Last update Tue May  9 10:49:04 2017 NANAA
*/

#include "raytracer.h"
#include "libmy.h"

int		listObject_add(t_listObject *list, t_object object)
{
  t_nodeObject	*node;

  node = malloc(sizeof (t_nodeObject));
  if (node == NULL)
    return (EXIT_ERROR);
  node->object = object;
  node->next = NULL;
  if (list->end == NULL)
    {
      node->id = 0;
      node->prev = NULL;
      list->begin = node;
      list->end = node;
    }
  else
    {
      list->end->next = node;
      node->prev = list->end;
      node->id = node->prev->id + 1;
      list->end = node;
    }
  list->count++;
  return (EXIT_SUCCESS);
}
