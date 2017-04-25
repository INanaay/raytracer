/*
** handle_poll_events.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Apr 14 17:53:04 2017 NANAA
** Last update Tue Apr 25 12:08:22 2017 NANAA
*/

#include "raytracer.h"

void		handle_poll_events(t_screen *screen)
{
  sfEvent	event;

  while (sfRenderWindow_pollEvent(screen->window, &event))
    {
      if ((event.type == sfEvtMouseButtonPressed) &&
	  (event.mouseButton.button == sfMouseLeft))
	check_button_hit(screen);
    }
}
