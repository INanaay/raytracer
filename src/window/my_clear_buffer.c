/*
** my_clear_buffer.c for Project-Master in /home/NANAA/Projets/raytracer2/src/window
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Tue May  2 15:50:42 2017 NANAA
** Last update Sun May 28 17:33:21 2017 NANAA
*/

#include "raytracer.h"

void		fill_black(t_my_framebuffer *buffer)
{
  sfVector2i	pos;

  pos.y = 0;
  while (pos.y < FRAMEBUFFER_DEFAULT_HEIGHT)
    {
      pos.x = 0;
      while (pos.x <= FRAMEBUFFER_DEFAULT_WIDTH)
	{
	  my_put_pixel(buffer, pos, sfBlack);
	  pos.x++;
	}
      pos.y++;
    }
}

void       	clear_buffer(t_my_framebuffer *buffer, int width, int height)
{
 register int  	i;
  int		size;

  i = 0;
  size = width * height * 4;
  while (i < size)
    {
      buffer->pixels[i] = 0;
      i++;
    }
}
