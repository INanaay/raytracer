/*
** draw_objects.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Apr 14 15:51:23 2017 NANAA
** Last update Wed Apr 26 11:49:01 2017 NANAA
*/

#include "raytracer.h"

int		find_nearest_intersect(t_listObject *objects, sfVector3f dir_vector, sfVector3f eyes)
{
  int		i;
  int		place;
  float		min;
  float		temp;
  t_nodeObject	*node;
  int		id;

  id = 0;
  node = objects->begin;
  min = node->object.intersect(dir_vector, eyes, node->object.position,
			       node->object.value);
  while (node != NULL)
    {
      node = node->next;
      temp = node->object.intersect(dir_vector, eyes, node->object.position,
				    node->object.value);
      if (temp < min && temp > 0)
	{
	  id = node->id;
	  min = temp;
	}
    }
  return (id);
  /*
  min = objects[0].intersect(eyes, dir_vector, objects[0].value);
  i = 1;
  place = 0;
  while (i < nb_objects)
    {
      temp = objects[i].intersect(eyes, dir_vector, objects[i].value);
      if (temp < min && temp > 0)
	{
	  place = i;
	  min = temp;
	}
      i++;
    }
    return (place);*/
}

void		draw_objects(t_my_framebuffer *buffer, t_listObject objects, sfVector3f eyes, int nb_objects)
{
  sfVector2i	screen_pos;
    sfVector3f	dir_vector;
  int		id;
  
  screen_pos = sfVector2i_create(SCENE_DEFAULT_X, 0);
  while (screen_pos.y < FRAMEBUFFER_DEFAULT_HEIGHT)
    {
      screen_pos.x = SCENE_DEFAULT_X;
      while (screen_pos.x < FRAMEBUFFER_DEFAULT_WIDTH + SCENE_DEFAULT_X)
	{
	  dir_vector = calc_dir_vector(eyes, screen_pos);
	  id = find_nearest_intersect(&objects, dir_vector, eyes);
	  screen_pos.x++;
	}
      screen_pos.y++;
    }
}
