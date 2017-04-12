/*
** button_hit.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Wed Apr 12 16:31:53 2017 NANAA
** Last update Wed Apr 12 17:28:33 2017 NANAA
*/

#include "raytracer.h"

int		is_button_hit(sfRenderWindow *window, t_button **buttons)
{
  int	i;
  sfVector2i	mouse_position;

  i = 0;
  mouse_position = sfMouse_getPositionRenderWindow(window);
  while (i < NB_BUTTONS)
    {
      if ((mouse_position.x >= buttons[i]->position.x &&
	  mouse_position.x <=  buttons[i]->position.x + 160) &&
	  (mouse_position.y >= buttons[i]->position.y &&
	   mouse_position.y <= buttons[i]->position.y + 74))
	{
	  printf("hit\n");
	}
      else
	printf("no hit\n");
      i++;
    }
  return (EXIT_SUCCESS);
}
