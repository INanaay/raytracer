/*
** handle_poll_events.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Apr 14 17:53:04 2017 NANAA
** Last update Fri Apr 28 12:21:21 2017 NANAA
*/

#include "raytracer.h"

int		handle_poll_events(t_screen *screen)
{
  sfEvent	event;

  while (sfRenderWindow_pollEvent(screen->window, &event))
    {
      if ((event.type == sfEvtMouseButtonPressed) &&
	  (event.mouseButton.button == sfMouseLeft))
	{
	  return (check_button_hit(screen));
	}
    }
}
