/*
** button_hit.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Wed Apr 12 16:31:53 2017 NANAA
** Last update Wed Apr 26 10:34:00 2017 NANAA
*/

#include "raytracer.h"

int		add_object(t_listObject *objects, int type)
{
  t_object		new_object;

  new_object = init_object(type);
  listObject_add(objects, new_object);  
}

int		check_button_hit(t_screen *screen)
{
  int	i;
  sfVector2i	mouse_position;
  int		count;

  count = screen->objects.count;
  printf("nb_obj%i\n", count);
  i = 0;
  mouse_position = sfMouse_getPositionRenderWindow(screen->window);
  while (i < NB_BUTTONS)
    {
      if ((mouse_position.x >= screen->buttons[i].position.x &&
	   mouse_position.x <=  screen->buttons[i].position.x + 160) &&
	  (mouse_position.y >= screen->buttons[i].position.y &&
	   mouse_position.y <= screen->buttons[i].position.y + 74))
	{
	  if (screen->buttons[i].id < 4)
	    add_object(&(screen->objects), screen->buttons[i].id);
	}
      i++;
    }
  return (EXIT_SUCCESS);
}
