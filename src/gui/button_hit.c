/*
** button_hit.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Wed Apr 12 16:31:53 2017 NANAA
** Last update Mon Apr 24 19:23:35 2017 NANAA
*/

#include "raytracer.h"

int		check_buttons(t_screen *screen)
{
  int	i;
  sfVector2i	mouse_position;

  i = 0;
  mouse_position = sfMouse_getPositionRenderWindow(screen->window);
  while (i < NB_BUTTONS)
    {
      if ((mouse_position.x >= screen->buttons[i].position.x &&
	  mouse_position.x <=  screen->buttons[i].position.x + 160) &&
	  (mouse_position.y >= screen->buttons[i].position.y &&
	   mouse_position.y <= screen->buttons[i].position.y + 74))
	{
	  if (screen->buttons[i].id % 2 == 0)
	    printf("add object\n");
	    //	  printf("button nb %i = hit\n", i + 1);
	}
      else
	printf("no hit\n");
      i++;
    }
  return (EXIT_SUCCESS);
}
