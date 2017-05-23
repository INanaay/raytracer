/*
** shadow.c for  in /home/anatole.zeyen/raytracer2
**
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
**
** Started on  Tue May 16 11:39:16 2017 anatole zeyen
** Last update Tue May 23 13:29:42 2017 NANAA
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

int			shadow(sfVector3f light_v, t_screen *screen,
			       t_object *current_obj, sfVector3f *inter_point)
{
  float			closest;
  t_nodeObject		*temp;
  sfVector3f		light_vector;
  sfVector3f		obj_pos;

  temp = screen->objects.begin;
  closest = -1.0;
  light_vector.x = -(screen->lights[0].coordinates.x - inter_point->x);
  light_vector.y = -(screen->lights[0].coordinates.y - inter_point->y);
  light_vector.z = -(screen->lights[0].coordinates.z - inter_point->z);
  while (temp != NULL)
    {
      obj_pos.x = temp->object.position.x - inter_point->x;
      obj_pos.y = temp->object.position.y - inter_point->y;
      obj_pos.z = temp->object.position.z - inter_point->z;
      closest =
	temp->object.intersect(&light_vector, &obj_pos,
			       &current_obj->position, temp->object.value);
      if (not_this_obj(current_obj, temp->object) && closest > 0.0
	  && closest < 1.0f)
	return (0);
      temp = temp->next;
    }
  return (1);
}
