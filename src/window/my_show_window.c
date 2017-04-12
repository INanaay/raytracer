/*
** my_show_window.c for wolf in /home/flavian.gontier/C_Graphical/wolf3d/src/graphic/window
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Mon Jan  2 15:22:10 2017 flavian gontier
** Last update Wed Apr 12 12:10:19 2017 NANAA
*/

#include <stdlib.h>
#include "raytracer.h"

void		show_window(sfRenderWindow *win, t_my_framebuffer *fuffer)
{
  sfSprite	*sprite;
  sfTexture	*texture;

  sprite = sfSprite_create();
  texture = sfTexture_create(fuffer->dimensions.x, fuffer->dimensions.y);
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfTexture_updateFromPixels(texture, fuffer->pixels, fuffer->dimensions.x,
			     fuffer->dimensions.y, 0, 0);
  while (sfRenderWindow_isOpen(win))
  {
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, sprite, NULL);
    sfRenderWindow_display(win);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
      sfRenderWindow_close(win);
  }
  sfRenderWindow_destroy(win);
  //  free(win);
}
