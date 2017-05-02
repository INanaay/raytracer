/*
** move_objects.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Tue May  2 14:00:37 2017 NANAA
** Last update Tue May  2 16:58:48 2017 NANAA
*/

#include "raytracer.h"

sfVector2i	calc_new_pos(sfVector2i mouse_position, sfVector2i new_position)
{
  if (new_position.x > mouse_position.x || new_position.x < mouse_position.x)
    new_position.x -= mouse_position.x;
  if (new_position.y > mouse_position.y || new_position.y < mouse_position.y)
    new_position.y -= mouse_position.y;
  return (new_position);
}

int		move_objects(sfVector2i mouse_position, t_screen *screen)
{
  int		id;
  t_nodeObject	*temp;
  sfVector3f	dir_vector;
  sfVector2i	new_position;

  while (sfMouse_isButtonPressed(sfMouseLeft))
    new_position =  sfMouse_getPositionRenderWindow(screen->window);
  new_position = calc_new_pos(mouse_position, new_position);
  dir_vector = calc_dir_vector(mouse_position);
  id = find_nearest_intersect(&(screen->objects), &dir_vector, &(screen->eyes));
  if (id == -1)
    {
      printf("no object\n");
      return (EXIT_ERROR);
    }
  temp = screen->objects.begin;
  while (temp->id != id)
    temp = temp->next;
  temp->object.position.y -= new_position.x;
  temp->object.position.z -= new_position.y;
  return (EXIT_SUCCESS);
}
