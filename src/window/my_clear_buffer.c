/*
** my_clear_buffer.c for Project-Master in /home/NANAA/Projets/raytracer2/src/window
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Tue May  2 15:50:42 2017 NANAA
** Last update Tue May  2 17:27:02 2017 NANAA
*/

#include "raytracer.h"

void       	clear_buffer(t_my_framebuffer *buffer, int width, int height)
{
 register int		i;
  int		size;

  i = 0;
  size = width * height * 4;
  while (i < size)
    {
      buffer->pixels[i] = 0;
      i++;
    }
}
