/*
** framebuffer.c for  in /home/NANAA/projets/raytracer1
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Feb 10 14:15:09 2017 Nathan Lebon
** Last update Fri Feb 10 14:15:58 2017 Nathan Lebon
*/

#include "include/ray.h"

void                    my_framebuffer_destroy(t_my_framebuffer *buff)
{
  free(buff);
}

t_my_framebuffer        *my_framebuffer_create(int width, int height)
{
  int                   i;
  t_my_framebuffer      *buff;

  buff = malloc(sizeof(t_my_framebuffer));
  buff->pixels = malloc(width * height * 4 * sizeof(*buff->pixels));
  if (buff->pixels == NULL)
    {
      return (NULL);
    }
  i = 0;
  while (i < width * height * 4)
    {
      buff->pixels[i] = 0;
      i = i + 1;
    }
  return (buff);
}
