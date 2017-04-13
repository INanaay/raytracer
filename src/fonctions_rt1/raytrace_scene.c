/*
** raytrace_scene.c for  in /home/NANAA/projets/raytracer1/bonus
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Tue Feb 28 17:16:02 2017 Nathan Lebon
** Last update Fri Mar 17 16:14:04 2017 NANAA
*/

#include <math.h>
#include <SFML/Graphics/Color.h>
#include "include/ray.h"

sfColor		change_color(sfColor color, int type, float cos)
{
  if (type == SPHERE)
    color.r = color.r * cos;
  else if (type == PLANE)
    color.b = color.b * cos;
  else if (type == CYL)
    color.g = color.g * cos;
  else if (type == CONE)
    {
      color.r = color.r * cos;
      color.g = color.r * cos;
    }
  return (color);
}

void		trace_object(t_object **objs, t_my_framebuffer *framebuffer,
			     t_eye *eye, int i)
{
  sfColor	color;
  sfVector3f	inter_point;
  sfVector3f	light_v;
  float		cos;
  sfVector3f	vector;

  inter_point = get_inter_point(eye, objs[i]->inter);
  color = set_color(objs[i]->type);
  light_v = light_vector(eye, eye->light_pos, objs[i]->inter);
  light_v = get_normal_vector(light_v);
  inter_point = get_normalized_object(inter_point, objs[i]);
  cos = get_light_coef(get_normal_vector(light_v), inter_point);
  color = change_color(color, objs[i]->type, cos);
  if (cos > 0)
    my_put_pixel(framebuffer, eye->pos.x, eye->pos.y, color);
  else
    my_put_pixel(framebuffer, eye->pos.x, eye->pos.y, sfBlack);

}

t_object	**calculate_all_inter(t_object **objs, t_eye *eye,
				      t_win *win, int i)
{
  if (objs[i]->type == SPHERE)
    objs[i]->inter = intersect_sphere(eye, objs[i]->radius, objs[i]);
  else if (objs[i]->type == PLANE)
    objs[i]->inter = intersect_plane(eye);
  else if (objs[i]->type == CYL)
    objs[i]->inter = intersect_cyl(eye, objs[i]->radius, objs[i]);
  else if (objs[i]->type == CONE)
    objs[i]->inter = intersect_cone(eye, objs[i]->radius);
  return (objs);
}

t_object	**get_inter(t_object **objs, t_eye *eye, t_win *win)
{
  int		i;
  int		place;

  eye->pos.y = 0;
  while (eye->pos.y < FRAMEBUFFER_HEIGHT)
    {
      eye->pos.x = 0;
      while (eye->pos.x < FRAMEBUFFER_WIDTH)
	{
	  i = 0;
	  calc_dir_vector(eye);
	  while (objs[i] != NULL)
	    {
	      objs = calculate_all_inter(objs, eye, win, i);
	      i++;
	    }
	  place = get_min_inter_place(objs);
	  trace_object(objs, win->buffer, eye, place);
	  eye->pos.x++;
	}
      eye->pos.y++;
    }
  return (objs);
}

int	raytrace_scene(t_eye *eye, t_object **objs, t_win *win)
{
  objs = get_inter(objs, eye, win);
}
