/*
** color.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Sat Apr 29 16:14:21 2017 NANAA
** Last update Thu May 25 19:17:58 2017 schwarzy
*/

# include <SFML/Graphics/Color.h>
#include "raytracer.h"

sfColor	get_real_color(sfColor color, float cos, sfColor obj_color)
{
  if (color.r == 255 && color.g == 255 && color.b == 255)
    return (obj_color);
  color.r = (color.r * cos) / 2 + (obj_color.r * cos) / 2;
  color.g = (color.g * cos) / 2 + (obj_color.g * cos) / 2;
  color.b = (color.b * cos) / 2 + (obj_color.b * cos) / 2;
  return (color);
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
