/*
** draw_objects.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Fri Apr 14 15:51:23 2017 NANAA
** Last update Fri May 26 17:45:33 2017 schwarzy
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

sfVector3f	change_object_color(t_inter inters, t_screen *screen,
				    sfVector3f *dir_vector, int index)
{
  sfVector3f	light_vector;
  sfVector3f	light_v;
  float		cos;
  t_object	*object;

  object = inters.object;
  inters.point = object->normal(inters.point, &(object->position),
			       object->value);
  light_vector = get_light_vector(&screen->eyes, &(*dir_vector),
				  &screen->lights[index].coordinates,
				  inters.inter);
  light_v = light_vector;
  light_vector = get_normal_vector(light_vector);
  cos = get_light_coef(&light_vector, &inters.point);
  change_color(&(object->color), cos);
  object->color = get_my_color(object, screen, &inters.point, &(*dir_vector));
  return (light_v);
}

float		multilight_shadow(t_inter inters, t_screen *screen,
				  sfVector3f *dir_vector)
{
  sfVector3f	light_vector;
  float		light_coef;
  size_t	index;

  index = 0;
  light_coef = 0;
  while (index < screen->lights_count)
    {
      light_vector = change_object_color(inters, screen, dir_vector, index);
      light_coef += shadow(light_vector, screen, inters);
      index++;
    }
  light_coef = light_coef / screen->lights_count;
  return (light_coef);
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
