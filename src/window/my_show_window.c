/*
** my_show_window.c for wolf in /home/flavian.gontier/C_Graphical/wolf3d/src/graphic/window
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Mon Jan  2 15:22:10 2017 flavian gontier
** Last update Tue Apr 18 11:48:42 2017 anatole zeyen
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
  my_put_pixel(&(screen->framebuffer), sfVector2i_create(10, 10), sfRed);
  sfTexture_updateFromPixels(texture, screen->framebuffer.pixels, screen->framebuffer.dimensions.x, screen->framebuffer.dimensions.y, 0, 0);
  while (sfRenderWindow_isOpen(screen->window))
  {
    sfRenderWindow_drawSprite(screen->window, sprite, NULL);
    sfRenderWindow_display(screen->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
      sfRenderWindow_close(screen->window);
    handle_poll_events(screen);
  }
  sfRenderWindow_destroy(screen->window);
  //  free(win);
}
