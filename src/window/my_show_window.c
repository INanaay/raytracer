/*
** my_show_window.c for wolf in /home/flavian.gontier/C_Graphical/wolf3d/src/graphic/window
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Mon Jan  2 15:22:10 2017 flavian gontier
** Last update Sat Apr 29 14:34:19 2017 NANAA
*/

#include <stdlib.h>
#include "raytracer.h"

void		show_window(t_screen *screen)
{
  sfSprite	*sprite;
  sfTexture	*texture;

  sprite = sfSprite_create();
  texture = sfTexture_create(screen->framebuffer.dimensions.x, screen->framebuffer.dimensions.y);
  sfSprite_setTexture(sprite, texture, sfTrue);
  //  draw_objects(&(screen->framebuffer), &(screen->objects), screen->eyes);
  sfTexture_updateFromPixels(texture, screen->framebuffer.pixels, screen->framebuffer.dimensions.x,  screen->framebuffer.dimensions.y, 0, 0);
  while (sfRenderWindow_isOpen(screen->window))
  {
    sfRenderWindow_drawSprite(screen->window, sprite, NULL);
    sfRenderWindow_display(screen->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
      sfRenderWindow_close(screen->window);
    if (handle_poll_events(screen) == BUTTON_HIT)
      {
	draw_objects(&(screen->framebuffer), &(screen->objects), screen->eyes, &(screen->lights));
	sfTexture_updateFromPixels(texture, screen->framebuffer.pixels, screen->framebuffer.dimensions.x,  screen->framebuffer.dimensions.y, 0, 0);
      };
  }
  sfRenderWindow_destroy(screen->window);
  //  free(win);
}
