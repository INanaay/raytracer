/*
** utils.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/tracing
**
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
**
** Started on  Tue Apr 11 11:58:46 2017 flavian gontier
** Last update Sun May 28 15:43:25 2017 schwarzy
*/

#include <math.h>
#include "raytracer.h"

void	my_put_pixel(t_framebuffer *buffer, sfVector2i coords, sfColor color)
{
  int	index;

  if (coords.x >= buffer->dimensions.x || coords.x < 0)
    return ;
  if (coords.y >= buffer->dimensions.y || coords.y < 0)
    return ;
  index = (buffer->dimensions.x * coords.y + coords.x) * 4;
  buffer->pixels[index] = color.r;
  buffer->pixels[index + 1] = color.g;
  buffer->pixels[index + 2] = color.b;
  buffer->pixels[index + 3] = color.a;
}

float	get_root(float a, float b, float delt)
{
  float	r1;
  float	r2;

  if (delt == 0)
    {
      r1 = (-b) / (2 * a);
      return (r1);
    }
  r1 = (-b + (float)sqrt(delt)) / (2 * a);
  r2 = (-b - (float)sqrt(delt)) / (2 * a);
  if (r1 > r2)
    return (r2);
  return (r1);
}

sfVector3f	apply_rotation(sfVector3f vector, sfVector3f rotation)
{
  if (rotation.x != 0 || rotation.y != 0 || rotation.z != 0)
    vector = rotate_xyz(vector, rotation);
  return (vector);
}

void		set_for_rotation(sfVector3f *dir_v, sfVector3f *eyes,
				 t_object *object)
{
  sfVector3f	pos;

  pos = inv_trans(object->position, object->position);
  *dir_v = apply_rotation(*dir_v, object->rotation);
  *eyes = apply_rotation(translate(*eyes, pos), object->rotation);
}
