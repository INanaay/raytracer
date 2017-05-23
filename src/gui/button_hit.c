/*
** button_hit.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Wed Apr 12 16:31:53 2017 NANAA
** Last update Tue May 23 12:25:24 2017 NANAA
*/

#include "raytracer.h"

int		is_cursor_on_button(sfVector2i mouse_position,
				    t_screen *screen, int i)
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

static int	modify_aliasing(t_screen *screen, int button_id)
{
  if (button_id == 12 && screen->aliasing > 1)
    {
      screen->aliasing--;
      return (EXIT_SUCCESS);
    }
  else if (button_id == 13 && screen->aliasing < 6)
    {
      screen->aliasing++;
      return (EXIT_SUCCESS);
    }
  return (EXIT_ERROR);
}

int		button_action(t_screen *screen, int i)
{
  if (screen->buttons[i].id < 3)
    {
      return (add_object(&(screen->objects), screen->buttons[i].id));
    }
  else if (screen->buttons[i].id == 5)
    {
      return (change_damier(&(*screen)));
    }
  else if (screen->buttons[i].id == 12 || screen->buttons[i].id == 13)
    return (modify_aliasing(&(*screen), screen->buttons[i].id));
  else if (screen->buttons[i].id == 14 || screen->buttons[i].id == 17)
    return (modify_size(&(*screen), screen->buttons[i].id));
  else if (screen->buttons[i].id == 15 && screen->last_object >= 1)
    {
      return (listObject_remove(&screen->objects, screen->last_object));
    }
  else
    {
      return (modify_color(&(*screen), screen->buttons[i].id));
    }
  return (EXIT_SUCCESS);
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
	  hit = BUTTON_HIT;
	  if (button_action(&(*screen), i) == EXIT_ERROR)
	    return (EXIT_ERROR);
	}
      i++;
    }
  if (hit == BUTTON_HIT)
    return (EXIT_SUCCESS);
  return (EXIT_ERROR);
}
