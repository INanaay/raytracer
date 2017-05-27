/*
** rotate_object.c for Project-Master in /home/NANAA/raytracer2
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Mon May 22 18:00:14 2017 NANAA
** Last update Sat May 27 12:22:33 2017 schwarzy
*/

#include "raytracer.h"

int		rotate_object(t_listObject *objects, int last_object_id)
{
  bool		moved;
  int		index;
  t_nodeObject	*temp;

  index = 0;
  temp = objects->begin;
  while (index < last_object_id)
    {
      temp = temp->next;
      index++;
    }
  moved = true;
  if (sfKeyboard_isKeyPressed(sfKeyK))
    temp->object.rotation.x -= 5;
  else if (sfKeyboard_isKeyPressed(sfKeyL))
    temp->object.rotation.x += 5;
  else
    moved = false;
  return (moved);
}
