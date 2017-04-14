/*
** print_gui.c for  in /home/anatole.zeyen/raytracer2/src/gui
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Tue Apr 11 14:03:40 2017 anatole zeyen
** Last update Fri Apr 14 19:33:49 2017 NANAA
*/

#include "raytracer.h"

int	print_gui(t_screen *screen)
{
  int	i;

  i = 0;
  while (i < NB_BUTTONS)
    {
      sfSprite_setPosition(screen->buttons[i].sprite, screen->buttons[i].position),
      sfRenderWindow_drawSprite(screen->window, screen->buttons[i].sprite, NULL);
      i++;
    }
  return (EXIT_SUCCESS);
}
