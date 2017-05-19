/*
** color.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Sat Apr 29 16:14:21 2017 NANAA
** Last update Fri May 19 13:28:27 2017 anatole zeyen
*/

# include <SFML/Graphics/Color.h>
#include "raytracer.h"

sfColor		get_my_color(t_object *object, t_screen *screen,
			     sfVector3f *inter_point, sfVector3f *dir_vector)
{
  sfColor	color;
  sfColor	sumcolor;
  size_t	x;
  float		cos;
  sfVector3f	light_vector;
  float		inter;

  x = 0;
  inter = object->intersect(&(*dir_vector), &(screen->eyes),
			    &object->position, object->value);
  sumcolor = sfBlack;
  while (x < screen->lights_count)
    {
      color = screen->lights[x].color;
      light_vector = get_light_vector(&(screen->eyes), &(*dir_vector),
				      &(screen->lights[x].coordinates), inter);
      light_vector = get_normal_vector(light_vector);
      cos = get_light_coef(&light_vector, &(*inter_point));
      color = get_real_color(color, cos, object->color);
      sumcolor.r = sumcolor.r + (int)(color.r / NBR_COLORS);
      sumcolor.g = sumcolor.g + (int)(color.g / NBR_COLORS);
      sumcolor.b = sumcolor.b + (int)(color.b / NBR_COLORS);
      x++;
    }
  return (sumcolor);
}

sfColor	get_real_color(sfColor color, float cos, sfColor obj_color)
{
  if (color.r == 255 && color.g == 255 && color.b == 255)
    return (obj_color);
  color.r = (color.r * cos) / 2 + (obj_color.r * cos) / 2;
  color.g = (color.g * cos) / 2 + (obj_color.g * cos) / 2;
  color.b = (color.b * cos) / 2 + (obj_color.b * cos) / 2;
  return (color);
}

sfColor		div_color_by_4(sfColor color)
{
  sfColor	new;

  new.r = color.r / 4;
  new.g = color.g / 4;
  new.b = color.b / 4;
  new.a = color.a;
  return (new);
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
