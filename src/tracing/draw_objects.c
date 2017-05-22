/*
** draw_objects.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Fri Apr 14 15:51:23 2017 NANAA
** Last update Mon May 22 16:05:09 2017 schwarzy
*/

#include "raytracer.h"

static void		aliasing(t_screen *screen, sfVector2i *screen_pos, t_object *object)
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

sfVector3f	change_object_color(sfVector3f inter_point, t_screen *screen,
				    t_object *object, sfVector3f *dir_vector)
{
  sfVector3f	light_vector;
  sfVector3f	light_v;
  float		cos;
  float		inter;

  inter = object->intersect(&(*dir_vector), &(screen->eyes),
			   &object->position, object->value);
  inter_point = object->normal(inter_point, &(object->position),
			       object->value);
  light_vector = get_light_vector(&(screen->eyes), &(*dir_vector),
				  &(screen->lights[0].coordinates), inter);
  light_v = light_vector;
  light_vector = get_normal_vector(light_vector);
  cos = get_light_coef(&light_vector, &inter_point);
  change_color(&(object->color), cos);
  object->color = get_my_color(object, screen, &inter_point, &(*dir_vector));
  return (light_v);
}

void		draw_pixel(t_screen *screen, sfVector2i *screen_pos,
			   sfVector3f *dir_vector, t_object *object)
{
  sfVector3f	inter_point;
  sfVector3f	light_vector;
  float		inter;
  float		light_coef;

  inter = object->intersect(&(*dir_vector), &(screen->eyes),
			    &object->position, object->value);
  inter_point = get_inter_point(&(screen->eyes), &(*dir_vector), inter);
  if (object->is_damier == true)
    damier(&inter_point, &object->color);
  light_vector = change_object_color(inter_point, screen, object, dir_vector);
  light_coef = shadow(light_vector, screen, object, &inter_point);
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
	dir_vector_copy = rotate_xyz(dir_vector_copy, node->object.rotation);
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
	  dir_vector = rotate_xyz(dir_vector, screen->rotate);
	  dir_vector = translate(dir_vector, screen->translate);
	  id = find_nearest_intersect(&(screen->objects), &dir_vector, &(screen->eyes));
	  if (id != -1)
	    {
	      obj = get_object_to_draw(&(screen->objects), id);
	      dir_vector = rotate_xyz(dir_vector, obj.rotation);
	      draw_pixel(&(*screen), &screen_pos, &dir_vector, &obj);
	    }
	  screen_pos.x = screen_pos.x + screen->aliasing;
	}
      screen_pos.y = screen_pos.y + screen->aliasing;
    }
}
