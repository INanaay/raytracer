/*
** screenshot.c for Project-Master in /home/NANAA/Projets/raytracer1/bonus
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Mar 17 13:38:24 2017 NANAA
** Last update Sun May 28 14:56:21 2017 NANAA
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "raytracer.h"

void		screenshot(t_my_framebuffer *buffer)
{
  sfImage	*ss;
  sfColor	color;
  int		i;
  int		j;

  i = 0;
  ss = sfImage_create(FRAMEBUFFER_DEFAULT_WIDTH,
		      FRAMEBUFFER_DEFAULT_HEIGHT);
  while (i < FRAMEBUFFER_DEFAULT_WIDTH)
    {
      j = 0;
      while (j < FRAMEBUFFER_DEFAULT_HEIGHT)
	{
	  color.r = buffer->pixels[(FRAMEBUFFER_DEFAULT_WIDTH * j + i) * 4];
	  color.g = buffer->pixels[(FRAMEBUFFER_DEFAULT_WIDTH * j + i) * 4 + 1];
	  color.b = buffer->pixels[(FRAMEBUFFER_DEFAULT_WIDTH * j + i) * 4 + 2];
	  color.a = buffer->pixels[(FRAMEBUFFER_DEFAULT_WIDTH * j + i) * 4 + 3];
	  sfImage_setPixel(ss, i, j, color);
	  j++;
	}
      i++;
    }
  sfImage_saveToFile(ss, "ss.bmp");
}
