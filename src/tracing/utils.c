/*
** utils.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/tracing
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Tue Apr 11 11:58:46 2017 flavian gontier
** Last update Fri Apr 14 17:03:56 2017 NANAA
*/

#include "raytracer.h"

void	my_put_pixel(t_framebuffer *buffer, sfVector2i coords, sfColor color)
{
  int	index;

  if (coords.x >= buffer->dimensions.x || coords.x < 0)
    return ;
  if (coords.y >= buffer->dimensions.y || coords.y < 0)
    return ;
  index = (buffer->dimensions.x * coords.y) + coords.x;
  buffer->pixels[index] = color.r;
  buffer->pixels[index + 1] = color.g;
  buffer->pixels[index + 2] = color.b;
  buffer->pixels[index + 3] = color.a;
}
