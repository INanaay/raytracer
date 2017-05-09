/*
** button_hit.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Wed Apr 12 16:31:53 2017 NANAA
** Last update Tue May  9 10:34:37 2017 NANAA
*/

#include "raytracer.h"

int		is_cursor_on_button(sfVector2i mouse_position, t_screen *screen, int i)
{
  if ((mouse_position.x >= screen->buttons[i].position.x &&
       mouse_position.x <=  screen->buttons[i].position.x + 160) &&
      (mouse_position.y >= screen->buttons[i].position.y &&
       mouse_position.y <= screen->buttons[i].position.y + 74))
    return (EXIT_SUCCESS);
  return (EXIT_ERROR);
   
}

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
      if (is_cursor_on_button(mouse_position, &(*screen), i) == EXIT_SUCCESS)
	{
	  if (screen->buttons[i].id < 3)
	    {
	      hit = BUTTON_HIT;
	      if (add_object(&(screen->objects), screen->buttons[i].id) == EXIT_ERROR)
		return (EXIT_ERROR);
	    }
	  else if (screen->buttons[i].id == 3)
	    {
	      hit = BUTTON_HIT;
	      if (listObject_remove(&(screen->objects), screen->last_object) == EXIT_ERROR)
		return (EXIT_ERROR);
	    }
	  else if (screen->buttons[i].id >= 4 && screen->buttons[i].id <= 9)
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
