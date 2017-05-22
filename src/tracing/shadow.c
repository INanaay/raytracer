/*
** shadow.c for  in /home/anatole.zeyen/raytracer2
**
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
**
** Started on  Tue May 16 11:39:16 2017 anatole zeyen
** Last update Mon May 22 15:58:24 2017 schwarzy
*/

#include "raytracer.h"

int	not_this_obj(t_object *current_obj, t_object other)
{
  if (current_obj->position.x == other.position.x
      && current_obj->position.y == other.position.y
      && current_obj->position.z == other.position.z
      && current_obj->value == other.value
      && current_obj->type == other.type)
    return (0);
  return (1);
}

float			shadow(sfVector3f light_v, t_screen *screen,
			       t_object *current_obj, sfVector3f *inter_point)
{
  float			closest;
  t_nodeObject		*temp;
  sfVector3f		obj_pos;

  temp = screen->objects.begin;
  light_v.x = -light_v.x;
  light_v.y = -light_v.y;
  light_v.z = -light_v.z;
  while (temp != NULL)
    {
      obj_pos.x = temp->object.position.x - inter_point->x;
      obj_pos.y = temp->object.position.y - inter_point->y;
      obj_pos.z = temp->object.position.z - inter_point->z;
      closest = temp->object.intersect(&light_v, &obj_pos,
				       &current_obj->position,
				       temp->object.value);
      if (not_this_obj(current_obj, temp->object)
	  && closest > 0.0f && closest < 1.0f)
	return (closest);
      temp = temp->next;
    }
  return (1.0);
}
