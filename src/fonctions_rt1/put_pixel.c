/*
** put_pixel.c for  in /home/NANAA/projets/raytracer1
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Feb 10 16:24:21 2017 Nathan Lebon
** Last update Fri Mar 17 13:46:59 2017 NANAA
*/

#include "include/ray.h"

void                    my_put_pixel(t_my_framebuffer *buff, int x,
                                     int y, sfColor color)
{

  if ((x >= 0 && x <= FRAMEBUFFER_WIDTH) &&
      (y >= 0 && y <= FRAMEBUFFER_HEIGHT))
    {
      buff->pixels[(FRAMEBUFFER_WIDTH * y + x) * 4] = color.r;
      buff->pixels[(FRAMEBUFFER_WIDTH * y + x) * 4 + 1] = color.g;
      buff->pixels[(FRAMEBUFFER_WIDTH * y + x) * 4 + 2] = color.b;
      buff->pixels[(FRAMEBUFFER_WIDTH * y + x) * 4 + 3] = color.a;
    }
}
