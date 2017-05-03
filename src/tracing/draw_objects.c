/*
** draw_objects.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Apr 14 15:51:23 2017 NANAA
** Last update Wed May  3 11:16:46 2017 NANAA
*/

#include "raytracer.h"

void		draw_pixel(t_screen *screen, sfVector2i *screen_pos, sfVector3f *dir_vector, t_object *object)
{
  sfVector3f	inter_point;
  sfVector3f	light_vector;
  float		cos;
  float		inter;

  inter = object->intersect(&(*dir_vector), &(screen->eyes), &object->position, object->value);
  inter_point = get_inter_point(&(screen->eyes), &(*dir_vector), inter);
  inter_point = object->normal(inter_point, &(object->position), object->value);
  light_vector = get_light_vector(&(screen->eyes), &(*dir_vector), &(screen->lights[0].coordinates), inter);
  light_vector = get_normal_vector(light_vector);
  cos = get_light_coef(&light_vector, &inter_point);
  change_color(&(object->color), cos);
  if (cos > 0)
    my_put_pixel(&(screen->framebuffer), *screen_pos, object->color);
}

int		find_nearest_intersect(t_listObject *objects, sfVector3f *dir_vector, sfVector3f *eyes)
{
  int		id;
  float		min;
  t_nodeObject	*node;
  size_t       	index;
  float		temp;

  min = 1000000;
  id = -1;
  if (objects->count == 0)
    return (id);
  node = objects->begin;
  id = 0;
  index = 0;
  while (index < objects->count)
    {
      temp = node->object.intersect(&(*dir_vector), &(*eyes), &node->object.position,
				    node->object.value);
      if (temp < min && temp > 0)
	{
	  id = node->id;
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

  temp = objects->begin;
  while (temp->id != id)
    {
      temp = temp->next;
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
	  id = find_nearest_intersect(&(screen->objects), &dir_vector, &(screen->eyes));
	  if (id != -1)
	    {
	      obj = get_object_to_draw(&(screen->objects), id);
	      draw_pixel(&(*screen), &screen_pos, &dir_vector, &obj);
	    }
	  screen_pos.x++;
	}
      screen_pos.y++;
    }
}
