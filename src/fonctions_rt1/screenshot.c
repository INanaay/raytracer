/*
** screenshot.c for Project-Master in /home/NANAA/Projets/raytracer1/bonus
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Mar 17 13:38:24 2017 NANAA
** Last update Fri Mar 17 15:52:10 2017 NANAA
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "include/ray.h"

void		screenshot(t_my_framebuffer *buffer)
{
  sfImage	*ss;
  sfColor	color;
  int		i;
  int		j;

  i = 0;
  ss = sfImage_create(FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT);
  while (i < FRAMEBUFFER_WIDTH)
    {
      j = 0;
      while (j < FRAMEBUFFER_WIDTH)
	{
	  color.r = buffer->pixels[(FRAMEBUFFER_WIDTH * j + i) * 4];
	  color.g = buffer->pixels[(640 * j + i) * 4 + 1];
	  color.b = buffer->pixels[(640 * j + i) * 4 + 2];
	  color.a = buffer->pixels[(640 * j + i) * 4 + 3];
	  sfImage_setPixel(ss, i, j, color);
	  j++;
	}
      i++;
    }
  sfImage_saveToFile(ss, "ss.bmp");
}
