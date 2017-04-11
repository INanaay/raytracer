/*
** my_show_window.c for wolf in /home/flavian.gontier/C_Graphical/wolf3d/src/graphic/window
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Mon Jan  2 15:22:10 2017 flavian gontier
** Last update Tue Apr 11 14:19:16 2017 anatole zeyen
*/

#include <stdlib.h>
#include "raytracer.h"

void		show_window(t_screen *screen)
{
  sfSprite	*sprite;
  sfTexture	*texture;

  sprite = sfSprite_create();
  texture = sfTexture_create(screen->framebuffer->dimensions.x, screen->framebuffer->dimensions.y);
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfTexture_updateFromPixels(texture, screen->framebuffer->pixels, screen->framebuffer->dimensions.x, screen->framebuffer->dimensions.y, 0, 0);
  while (sfRenderWindow_isOpen(screen->win))
  {
    sfRenderWindow_clear(screen->win, sfBlack);
    sfRenderWindow_drawSprite(screen->win, sprite, NULL);
    sfRenderWindow_display(screen->win);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
      sfRenderWindow_close(screen->win);
  }
  sfRenderWindow_destroy(screen->win);
  //  free(win);
}
