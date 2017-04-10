/*
** my_create_framebuffer.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer1/src/graphic
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Tue Feb 14 13:58:34 2017 flavian gontier
** Last update Mon Apr 10 18:14:44 2017 NANAA
*/

#include <stdlib.h>
#include "raytracer.h"

sfUint8			*my_create_framebuffer_pixels(int pixel_count)
{
  sfUint8		*result;
  sfUint32		byte_count;

  byte_count = pixel_count * BYTES_PER_PIXEL;
  result = malloc(sizeof(sfUint8) * byte_count);
  if (result == NULL)
    return (NULL);
  return (result);
}

t_my_framebuffer	my_create_framebuffer(int width, int height)
{
  t_my_framebuffer	result;

  result.dimensions.x = width;
  result.dimensions.y = height;
  result.pixel_count = width * height;
  result.pixels = my_create_framebuffer_pixels(result.pixel_count);
  if (result.pixels == NULL)
  {
    result.dimensions.x = 0;
    result.dimensions.x = 0;
  }
  return (result);
}
