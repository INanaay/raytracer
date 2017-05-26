/*
** color.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Sat Apr 29 16:14:21 2017 NANAA
** Last update Fri May 26 19:17:33 2017 schwarzy
*/

# include <SFML/Graphics/Color.h>
#include "raytracer.h"

sfColor	diffuse_color(sfColor color, float cos, sfColor obj_color, float spec)
{
  if (color.r == 255 && color.g == 255 && color.b == 255)
    {
      change_color(&obj_color, cos);
      return (obj_color);
    }
  obj_color.r = color.r * cos * spec;
  obj_color.g = color.g * cos * spec;
  obj_color.b = color.b * cos * spec;
  return (obj_color);
}

sfColor		divide_color(sfColor color, int ratio)
{
  color.r /= ratio;
  color.g /= ratio;
  color.b /= ratio;
  return (color);
}

sfColor		sum_colors(sfColor a, sfColor b, int ratio)
{
  b = divide_color(b, ratio);
  a.r += b.r;
  a.g += b.g;
  a.b += b.b;
  return (a);
}

sfColor		create_color(int r, int g, int b, int alpha)
{
  sfColor	color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = alpha;
  return (color);
}

void		change_color(sfColor *color, float cos)
{
  color->r *= cos;
  color->g *= cos;
  color->b *= cos;
}
