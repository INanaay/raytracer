/*
** my_put_pixel.c for wolf in /home/flavian.gontier/C_Graphical/wolf3d/src/graphic
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Sat Dec 31 12:48:11 2016 flavian gontier
** Last update Mon Apr 10 19:00:30 2017 NANAA
*/

#include "raytracer.h"

void    my_put_pixel(t_my_framebuffer *framebuffer, int x, int y,
		     sfColor color)
{
  int   index;

  if (x < 0 || y < 0)
    return ;
  if (x > framebuffer->dimensions.x || y > framebuffer->dimensions.y)
    return ;
  index = (framebuffer->dimensions.x * y + x) * 4;
  framebuffer->pixels[index] = color.r;
  framebuffer->pixels[index + 1] = color.g;
  framebuffer->pixels[index + 2] = color.b;
  framebuffer->pixels[index + 3] = color.a;
}
