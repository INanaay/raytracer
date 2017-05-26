/*
** print_gui.c for  in /home/anatole.zeyen/raytracer2/src/gui
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Tue Apr 11 14:03:40 2017 anatole zeyen
** Last update Fri May 26 15:02:15 2017 NANAA
*/

#include "raytracer.h"

void		print_gui(t_screen *screen)
{
  int		i;
  sfText	*text;
  sfVector2f	pos;

  i = 0;
  text = create_text();
  while (i < NB_BUTTONS)
    {
      sfSprite_setPosition(screen->buttons[i].sprite,
			   screen->buttons[i].position),
      sfRenderWindow_drawSprite(screen->window,
				screen->buttons[i].sprite, NULL);
      pos.x = screen->buttons[i].position.x + 40;
      pos.y = screen->buttons[i].position.y + 10;
      sfText_setPosition(text, pos);
      sfText_setString(text, screen->buttons[i].text);
      sfRenderWindow_drawText(screen->window, text, NULL);
      i++;
    }
}
