/*
** window.c for  in /home/NANAA/projets/raytracer1/include
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Feb 10 14:04:59 2017 Nathan Lebon
** Last update Wed Apr 12 14:49:31 2017 NANAA
*/

#include "include/ray.h"

t_my_framebuffer        *clear_buffer(t_my_framebuffer *buff)
{
  int                   i;

  i = 0;
   while (i < FRAMEBUFFER_WIDTH * FRAMEBUFFER_HEIGHT * 4)
    {
      buff->pixels[i] = 0;
      i = i + 1;
    }
   return (buff);
}

sfRenderWindow         *create_window(char* name, int width, int height)
{
  sfRenderWindow*       window;
  sfVideoMode           mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    {
      return (NULL);
    }
  return (window);
}

t_win		*set_window()
{
  t_win		*win;

  if ((win = malloc(sizeof (t_win))) == NULL)
    return (NULL);
  win->window = create_window("raytracer", FRAMEBUFFER_WIDTH,
			      FRAMEBUFFER_HEIGHT);
  win->buffer = my_framebuffer_create(FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT);
  win->texture = sfTexture_create(FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT);
  win->sprite = sfSprite_create();
  sfSprite_setTexture(win->sprite, win->texture, sfTrue);
  sfTexture_updateFromPixels(win->texture, win->buffer->pixels,
  FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT, 0, 0);
  return (win);
}

int	open_window(t_win *win, t_object **objs, t_eye *eye)
{
  sfTexture_updateFromPixels(win->texture, win->buffer->pixels,
			     FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT, 0, 0);
  while (sfRenderWindow_isOpen(win->window))
    {
      sfRenderWindow_clear(win->window, sfBlack);
      sfRenderWindow_drawSprite(win->window, win->sprite, NULL);
      sfRenderWindow_display(win->window);
      if (move_object(eye) == 1 || (move_light(eye) == 1))
	{
	  win->buffer = clear_buffer(win->buffer);
	  raytrace_scene(eye, objs, win);
	  sfTexture_updateFromPixels(win->texture, win->buffer->pixels,
				     FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT, 0, 0);
	}
      if (sfKeyboard_isKeyPressed(sfKeySpace))
	{
	  screenshot(win->buffer);
	  sfRenderWindow_close(win->window);
	}
      if (sfKeyboard_isKeyPressed(sfKeyEscape))
	sfRenderWindow_close(win->window);
    }
  sfRenderWindow_destroy(win->window);
  free(win);
}
