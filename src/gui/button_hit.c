/*
** button_hit.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Wed Apr 12 16:31:53 2017 NANAA
** Last update Sat May  6 12:12:22 2017 NANAA
*/

#include "raytracer.h"

int		add_object(t_listObject *objects, int type)
{
  t_object		new_object;

  new_object = init_object(type);
  return (listObject_add(objects, new_object));
}

int		check_button_hit(t_screen *screen, sfVector2i mouse_position)
{
  int		i;
  int		hit;

  hit = 0;
  i = 0;
  while (i < NB_BUTTONS)
    {
      if ((mouse_position.x >= screen->buttons[i].position.x &&
	   mouse_position.x <=  screen->buttons[i].position.x + 160) &&
	  (mouse_position.y >= screen->buttons[i].position.y &&
	   mouse_position.y <= screen->buttons[i].position.y + 74))
	{
	  if (screen->buttons[i].id < 4)
	    {
	      hit = BUTTON_HIT;
	      if (add_object(&(screen->objects), screen->buttons[i].id) == EXIT_ERROR)
		return (EXIT_ERROR);
	    }
	  if (screen->buttons[i].id >= 4 && screen->buttons[i].id <= 9)
	    {
	      hit = BUTTON_HIT;
	      if (modify_color(&(*screen), screen->buttons[i].id) == EXIT_ERROR)
		return (EXIT_ERROR);
	    }
	}
      i++;
    }
  if (hit == BUTTON_HIT)
    return (EXIT_SUCCESS);
  return (EXIT_ERROR);
}
