/*
** draw_objects.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Fri Apr 14 15:51:23 2017 NANAA
** Last update Sat May 27 11:21:49 2017 schwarzy
*/

#include "raytracer.h"

static void		aliasing(t_screen *screen, sfVector2i *screen_pos,
				 t_object *object)
{
  sfVector2i		to_reach;

  to_reach.x = screen_pos->x + screen->aliasing;
  while (to_reach.x > screen_pos->x)
    {
      to_reach.y = screen_pos->y + screen->aliasing;
      while (to_reach.y > screen_pos->y)
	{
	  my_put_pixel(&(screen->framebuffer), to_reach, object->color);
	  to_reach.y--;
	}
      to_reach.x--;
    }
}

t_vlight	get_vlight(t_inter inters, t_screen *screen,
			   sfVector3f *dir_vector, int index)
{
  t_vlight	light;
  t_object	*obj;

  obj = inters.object;
  inters.point = obj->normal(inters.point, &obj->position, obj->value);
  light.vl = get_light_vector(&screen->eyes, dir_vector,
			      &screen->lights[index].coordinates, inters.inter);
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

void		draw_pixel(t_screen *screen, sfVector2i *screen_pos,
			   sfVector3f *dir_vector, t_object *object)
{
  t_inter	inters;
  float		light_coef;

  inters.inter = object->intersect(&(*dir_vector), &(screen->eyes),
			    &object->position, object->value);
  inters.point = get_inter_point(&(screen->eyes), &(*dir_vector), inters.inter);
  inters.object = object;
  if (object->is_damier == true)
    damier(&inters.point, &object->color);
  light_coef = multilight_shadow(inters, screen, dir_vector);
  change_color(&object->color, light_coef);
  aliasing(screen, screen_pos, object);
}

int		find_nearest_intersect(t_listObject *objects,
				       sfVector3f *dir_vector, sfVector3f *eyes)
{
  int		id;
  float		min;
  t_nodeObject	*node;
  size_t       	index;
  float		temp;
  sfVector3f	dir_vector_copy;

  min = 1000000;
  id = -1;
  if (objects->count == 0)
    return (id);
  node = objects->begin;
  id = 0;
  index = 0;
  while (index < objects->count)
    {
      dir_vector_copy = sfVector3f_cpy(*dir_vector);
      if (node->object.rotation.x != 0)
	dir_vector_copy = apply_rotation(dir_vector_copy, node->object.rotation);
      temp = node->object.intersect(&(dir_vector_copy), &(*eyes), &node->object.position,
				    node->object.value);
      if (temp < min && temp > 0)
	{
	  id = index;
	  min = temp;
	}
      node = node->next;
      index++;
    }
  if (min == 1000000)
    return (- 1);
  return (id);
}

t_object	get_object_to_draw(t_listObject *objects, int id)
{
  t_nodeObject	*temp;
  int		index;

  index = 0;
  temp = objects->begin;
  while (index != id)
    {
      temp = temp->next;
      index++;
    }
  return (temp->object);
}

void		draw_objects(t_screen *screen)
{
  sfVector2i	screen_pos;
  sfVector3f	dir_vector;
  int		id;
  t_object	obj;

  screen_pos = sfVector2i_create(0, 0);
  while (screen_pos.y < FRAMEBUFFER_DEFAULT_HEIGHT)
    {
      screen_pos.x = 0;
      while (screen_pos.x < FRAMEBUFFER_DEFAULT_WIDTH)
	{
	  dir_vector = calc_dir_vector(screen_pos);
	  dir_vector = apply_rotation(dir_vector, screen->rotate);
	  id = find_nearest_intersect(&(screen->objects), &dir_vector, &(screen->eyes));
	  if (id != -1)
	    {
	      obj = get_object_to_draw(&(screen->objects), id);
	      dir_vector = apply_rotation(dir_vector, obj.rotation);
	      draw_pixel(&(*screen), &screen_pos, &dir_vector, &obj);
	    }
	  screen_pos.x = screen_pos.x + screen->aliasing;
	}
      screen_pos.y = screen_pos.y + screen->aliasing;
    }
}
