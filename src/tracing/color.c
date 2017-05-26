/*
** color.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Sat Apr 29 16:14:21 2017 NANAA
** Last update Fri May 26 18:44:45 2017 schwarzy
*/

# include <SFML/Graphics/Color.h>
#include "raytracer.h"

sfColor	diffuse_color(sfColor color, float cos, sfColor obj_color)
{
  if (color.r == 255 && color.g == 255 && color.b == 255)
    return (obj_color);
  color.r = (color.r * cos) / 2 + (obj_color.r * cos) / 2;
  color.g = (color.g * cos) / 2 + (obj_color.g * cos) / 2;
  color.b = (color.b * cos) / 2 + (obj_color.b * cos) / 2;
  return (color);
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
