/*
** utils.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/tracing
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Tue Apr 11 11:58:46 2017 flavian gontier
** Last update Wed Apr 12 15:58:44 2017 NANAA
*/

#include "raytracer.h"

void	my_put_pixel(t_framebuffer *buffer, sfVector2i coords, sfColor color)
{
  int	index;
  int	height;

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
