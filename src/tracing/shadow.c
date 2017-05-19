/*
** shadow.c for  in /home/anatole.zeyen/raytracer2
**
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
**
** Started on  Tue May 16 11:39:16 2017 anatole zeyen
** Last update Fri May 19 13:35:46 2017 anatole zeyen
*/

#include "raytracer.h"

int	compare_current_obj_and_other(t_object *current_obj, t_object other)
{
  if (current_obj->type != other.type)
    return (1);
  if (current_obj->position.x == other.position.x && current_obj->position.y
      == other.position.y &&
      current_obj->position.z == other.position.z && current_obj->value ==
      other.value)
    return (0);
  return (1);
}

int			shadow(sfVector3f light_v, t_screen *screen,
			       t_object *current_obj, sfVector3f *inter_point)
{
  unsigned int		x;
  float			closest;
  t_nodeObject		*temp;
  sfVector3f		dir_vector;
  sfVector3f		obj_pos;

  x = 0;
  temp = screen->objects.begin;
  closest = -1.0;
  dir_vector.x = -light_v.x;
  dir_vector.y = -light_v.y;
  dir_vector.z = -light_v.z;
  while (x < screen->objects.count)
    {
      obj_pos.x = temp->object.position.x - inter_point->x;
      obj_pos.y = temp->object.position.y - inter_point->y;
      obj_pos.z = temp->object.position.z - inter_point->z;
      closest = temp->object.intersect(&dir_vector, &obj_pos, &temp->
				       object.position, temp->object.value);
      if ((compare_current_obj_and_other(current_obj, temp->object)) != 0 &&
	  (closest > 0.0f) &&
	  ((current_obj->position.z + current_obj->value <
	    screen->lights->coordinates.z) || (temp->object.position.z / 2>
					       screen->lights->coordinates.z)))
	return (0);
      x++;
      temp = temp->next;
    }
  return (1);
}
