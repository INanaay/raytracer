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

#define LUM_AMBIANT 1.2f

sfColor		change_color(sfColor color, int type, float cos)
{
  color.r = color.r * cos * LUM_AMBIANT;
  color.b = color.b * cos * LUM_AMBIANT;
  color.g = color.g * cos * LUM_AMBIANT;
  if (color.r > 255)
    color.r = 255;
  if (color.g > 255)
    color.g = 255;
  if (color.b > 255)
    color.b = 255;
  return (color);
}

int		nb_colors(t_eye *eye)
{
  int	x;

  x = 0;
  while (eye->light_pos[x])
    {
      x++;
    }
  return (x);
}

sfColor		get_color(t_object **objs, t_eye *eye, int i, int x)
{
  sfColor       color;
  sfVector3f    inter_point;
  sfVector3f    light_v;
  float         cos;
  sfVector3f    vector;
  sfColor	sumcolor;

  sumcolor = sfBlack;
  inter_point = get_inter_point(eye, objs[i]->inter);
  while (eye->light_color[x])
    {
      color = eye->light_color[x];
      light_v = light_vector(eye, eye->light_pos[x], objs[i]->inter);
      light_v = get_normal_vector(light_v);
      inter_point = get_normalized_object(inter_point, objs[i]);
      cos = get_light_coef(get_normal_vector(light_v), inter_point);
      color = change_color(color, objs[i]->type, cos);
      x++;
      sumcolor.r = sumcolor.r + (color.r * nb_colors(eye));
      sumcolor.g = sumcolor.g + (color.g * nb_colors(eye));
      sumcolor.b = sumcolor.b + (color.b * nb_colors(eye));
    }
  return (sumcolor);
}

void		trace_object(t_object **objs, t_my_framebuffer *framebuffer,
			     t_eye *eye, int i)
{
  sfColor	color;
  int		x;

  x = 0;
  color = get_color(objs, eye, i, x);
  my_put_pixel(framebuffer, eye->pos.x, eye->pos.y, color); // y'a un bail avec cos > 0 et sfblack mais ça devrait marcher sans : s'il n'y a pas de couleur, on renvoie sfBlack
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
