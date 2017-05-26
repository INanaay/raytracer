/*
** shadow.c for  in /home/anatole.zeyen/raytracer2
**
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
**
** Started on  Tue May 16 11:39:16 2017 anatole zeyen
** Last update Fri May 26 17:56:24 2017 schwarzy
*/

#include "raytracer.h"

int	is_same(t_object *current_obj, t_object other)
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
			       t_inter inters)
{
  float			closest;
  t_nodeObject		*tmp;
  t_object		*obj;
  sfVector3f		tmp_pos;

  obj = inters.object;
  tmp = screen->objects.begin;
  light_v.x = -light_v.x;
  light_v.y = -light_v.y;
  light_v.z = -light_v.z;
  while (tmp != NULL)
    {
      tmp_pos = inv_trans(tmp->object.position, inters.point);
      closest = tmp->object.intersect(&light_v, &tmp_pos,
				       &obj->position, tmp->object.value);
      if (is_same(obj, tmp->object) && closest > 0.0f && closest < 1.0f)
	return (closest);
      tmp = tmp->next;
    }
  return (1.0);
}
