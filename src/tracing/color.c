/*
** color.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Sat Apr 29 16:14:21 2017 NANAA
** Last update Thu May 25 22:55:22 2017 schwarzy
*/

# include <SFML/Graphics/Color.h>
#include "raytracer.h"

sfColor	get_real_color(sfColor color, float cos,
		       sfColor obj_color, float spec)
{
  if (color.r != 255 || color.g != 255 || color.b != 255)
    {
      obj_color.r = (color.r + obj_color.r) * cos / 2;
      obj_color.g = (color.g + obj_color.g) * cos / 2;
      obj_color.b = (color.b + obj_color.b) * cos / 2;
      }
  else
    {
      obj_color.r *= cos;
      obj_color.g *= cos;
      obj_color.b *= cos;
    }
  return (obj_color);
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
