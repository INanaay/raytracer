/*
** handle_poll_events.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Apr 14 17:53:04 2017 NANAA
** Last update Tue May  2 15:26:54 2017 NANAA
*/

#include "raytracer.h"

int		handle_poll_events(t_screen *screen)
{
  sfEvent	event;
  sfVector2i	mouse_position;

  mouse_position = sfMouse_getPositionRenderWindow(screen->window);
  while (sfRenderWindow_pollEvent(screen->window, &event))
    {
      if ((event.type == sfEvtMouseButtonPressed) &&
	  (event.mouseButton.button == sfMouseLeft))
	{
	  if (check_button_hit(screen, mouse_position) == EXIT_SUCCESS)
	    return (EXIT_SUCCESS);
	  else if (move_objects(mouse_position, &(*screen)) == EXIT_SUCCESS)
	    return (EXIT_SUCCESS);
	}
    }
  return (EXIT_ERROR);
}
