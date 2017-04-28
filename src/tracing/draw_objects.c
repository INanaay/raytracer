/*
** draw_objects.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Apr 14 15:51:23 2017 NANAA
** Last update Fri Apr 28 15:18:37 2017 NANAA
*/

#include "raytracer.h"

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
  return (id);
  
  
  /*
  int		i;
  int		place;
  float		min;
  float		temp;
  t_nodeObject	*node;
  int		id;
  size_t       	index;
  
  id = -1;
  if (objects->count == 0)
    return (id);
  id = 0;
  node = objects->begin;
  min = node->object.intersect(&(*dir_vector), &(*eyes), &node->object.position,
			       node->object.value);
  index = 1;
  while (index < objects->count)
    {
      node = node->next;
      temp = node->object.intersect(&(*dir_vector), &(*eyes), &node->object.position,
				    node->object.value);
      if (temp < min && temp > 0)
	{
	  id = node->id;
	  min = temp;
	}
      index ++;
    }
    return (id);*/
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

void		draw_objects(t_my_framebuffer *buffer, t_listObject *objects, sfVector3f eyes)
{
  sfVector2i	screen_pos;
  sfVector3f	dir_vector;
  int		id;
  t_object	obj;
  float		inter;
  
  screen_pos = sfVector2i_create(0, 0);
  while (screen_pos.y < FRAMEBUFFER_DEFAULT_HEIGHT)
    {
      screen_pos.x = 0;
      while (screen_pos.x < FRAMEBUFFER_DEFAULT_WIDTH)
	{
	  dir_vector = calc_dir_vector(eyes, screen_pos);
	  id = find_nearest_intersect(&(*objects), &dir_vector, &eyes);
	  if (id != -1)
	    {
	      obj = get_object_to_draw(&(*objects), id);
	      inter = obj.intersect(&dir_vector, &eyes, &obj.position, obj.value);
	      if (inter > 0)
		{
		  my_put_pixel(buffer, screen_pos, sfRed);
		}
	    }
	  screen_pos.x++;
	}
      screen_pos.y++;
    }
}
