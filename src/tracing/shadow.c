/*
** shadow.c for  in /home/anatole.zeyen/raytracer2
**
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
**
** Started on  Tue May 16 11:39:16 2017 anatole zeyen
** Last update Sat May 27 12:23:06 2017 schwarzy
*/

#include "raytracer.h"

static int	is_same(t_object *current_obj, t_object other)
{
  if (current_obj->position.x == other.position.x
      && current_obj->position.y == other.position.y
      && current_obj->position.z == other.position.z
      && current_obj->value == other.value
      && current_obj->type == other.type)
    return (0);
  return (1);
}

static float			shadow(sfVector3f light_v,
				       t_screen *screen, t_inter inters)
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

static t_vlight	get_vlight(t_inter inters, t_screen *screen,
			   sfVector3f *dir_vector, int index)
{
  t_vlight	light;
  t_object	*obj;

  obj = inters.object;
  inters.point = obj->normal(inters.point, &obj->position, obj->value);
  light.vl = get_light_vector(&screen->eyes, dir_vector,
			      &screen->lights[index].coordinates,
			      inters.inter);
  light.vln = get_normal_vector(light.vl);
  light.cos = get_light_coef(&light.vln, &inters.point);
  change_color(&obj->color, light.cos);
  return (light);
}

float		multilight_shadow(t_inter inters, t_screen *screen,
				  sfVector3f *dir_vector)
{
  size_t	index;
  t_vlight	light;
  sfColor	pixel;
  sfColor	diff;
  t_object	*obj;
  float		cos;

  obj = inters.object;
  index = 0;
  cos = 0;
  pixel = sfBlack;
  while (index < screen->lights_count)
    {
      light = get_vlight(inters, screen, dir_vector, index);
      diff = diffuse_color(screen->lights[index].color, light.cos,
			   obj->color, obj->spec);
      pixel = sum_colors(pixel, diff, screen->lights_count);
      cos += shadow(light.vl, screen, inters);
      index++;
    }
  obj->color = pixel;
  cos = cos / screen->lights_count;
  return (cos);
}
