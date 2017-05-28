/*
** shadow.c for  in /home/anatole.zeyen/raytracer2
**
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
**
** Started on  Tue May 16 11:39:16 2017 anatole zeyen
** Last update Sun May 28 19:02:17 2017 schwarzy
*/

#include "raytracer.h"

static bool	is_same(t_object *current_obj, t_object other)
{
  if (current_obj->position.x == other.position.x
      && current_obj->position.y == other.position.y
      && current_obj->position.z == other.position.z
      && current_obj->value == other.value
      && current_obj->type == other.type)
    return (true);
  return (false);
}

static float	get_shadow_inter(t_object *curr, t_object *obj,
				 sfVector3f *light_v, sfVector3f *pos)
{
  float		k;

  k = 0;
  if (curr->limited)
    pos->z -= (curr->lim);
  k = curr->intersect(light_v, pos, &obj->position, curr->value);
  return (k);
}

static float			shadow(sfVector3f light_v,
				       t_screen *screen, t_inter inters)
{
  float			k;
  t_nodeObject		*node;
  t_object		*obj;
  t_object		tmp;
  sfVector3f		tmp_pos;

  obj = inters.object;
  node = screen->objects.begin;
  light_v.x = -light_v.x;
  light_v.y = -light_v.y;
  light_v.z = -light_v.z;
  while (node != NULL)
    {
      tmp = node->object;
      tmp_pos = inv_trans(tmp.position, inters.point);
      set_for_rotation(&light_v, &inters.eyes, &tmp);
      k = get_shadow_inter(&tmp, obj, &light_v, &tmp_pos);
      if (!is_same(obj, tmp) && k > 0.0f && k < 1.0f)
	return (k);
      node = node->next;
    }
  return (1.0);
}

static t_vlight	get_vlight(t_inter inters, t_screen *screen, int index)
{
  t_vlight	light;
  t_object	*obj;

  obj = inters.object;
  inters.point = obj->normal(inters.point, &obj->position, obj->value);
  light.vl = get_light_vector(&inters.eyes, &inters.dir_v,
			      &screen->lights[index].coordinates,
			      inters.inter);
  light.vln = get_normal_vector(light.vl);
  light.cos = get_light_coef(&light.vln, &inters.point);
  change_color(&obj->color, light.cos);
  return (light);
}

float		multilight_shadow(t_inter inters, t_screen *screen)
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
      light = get_vlight(inters, screen, index);
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
