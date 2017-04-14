/*
** draw_objects.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Apr 14 15:51:23 2017 NANAA
** Last update Fri Apr 14 17:48:08 2017 NANAA
*/

#include "raytracer.h"

sfVector3f	calc_dir_vector(int pos_x, int pos_y)
{
  sfVector3f	dir_vector;

  dir_vector.x = FRAMEBUFFER_DEFAULT_WIDTH;
  dir_vector.y = (FRAMEBUFFER_DEFAULT_WIDTH / 2) - pos_x;
  dir_vector.z = (FRAMEBUFFER_DEFAULT_HEIGHT / 2) - pos_y;
  return (dir_vector);
}

int		find_nearest_intersect(t_object **objects, sfVector3f dir_vector, sfVector3f eyes)
{
  int		i;
  int		place;
  float		min;
  float		temp;

  min = objects[0]->intersect(eyes, dir_vector, objects[0]->value);
  i = 1;
  place = 0;
  while (objects[i])
    {
      temp = objects[i]->intersect(eyes, dir_vector, objects[i]->value);
      if (temp < min && temp > 0)
	{
	  place = i;
	  min = temp;
	}
      i++;
    }
  return (place);
}

void		draw_objects(t_my_framebuffer *buffer, t_object **objects, sfVector3f eyes)
{
  sfVector2i	screen_pos;
  int		i;
  sfVector3f	dir_vector;
  int		place;
  
  screen_pos = sfVector2i_create(FRAMEBUFFER_X_POSITION, 0);
  screen_pos.y = 0;
  while (screen_pos.y < FRAMEBUFFER_DEFAULT_HEIGHT)
    {
      screen_pos.x = FRAMEBUFFER_X_POSITION;
      while (screen_pos.x < FRAMEBUFFER_DEFAULT_WIDTH)
	{
	  dir_vector = calc_dir_vector(screen_pos.x, screen_pos.y);
	  place = find_nearest_intersect(&(*objects), dir_vector, eyes);
	  //raytrace_Scene
	  screen_pos.x++;
	}
      screen_pos.y++;
    }
  
}
