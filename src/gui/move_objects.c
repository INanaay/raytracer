/*
** move_objects.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Tue May  2 14:00:37 2017 NANAA
** Last update Thu May  4 11:18:09 2017 NANAA
*/

#include "raytracer.h"

sfVector2i	calc_new_pos(sfVector2i mouse_position, sfVector2i new_position)
{
  if (mouse_position.x == new_position.x && mouse_position.y == new_position.y)
    return (sfVector2i_create(0, 0));
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
  float		x;

  x = 0;
  new_position = sfVector2i_create(0, 0);
  while (sfMouse_isButtonPressed(sfMouseLeft))
    {
      new_position = sfMouse_getPositionRenderWindow(screen->window);
      if (sfKeyboard_isKeyPressed(sfKeyPageDown))
	x += 0.02;
      if (sfKeyboard_isKeyPressed(sfKeyPageUp))
	x -= 0.02;
    }
  printf("mouse pos : %i, %i\n", mouse_position.x, mouse_position.y);
  printf("new pos : %i, %i\n", new_position.x, new_position.y);
  new_position = calc_new_pos(mouse_position, new_position);
  dir_vector = calc_dir_vector(mouse_position);
  id = find_nearest_intersect(&(screen->objects), &dir_vector, &(screen->eyes));
  if (id == -1)
      return (EXIT_ERROR);
  temp = screen->objects.begin;
  while (temp->id != id)
    temp = temp->next;
   printf("before : %f, %f, %f\n", temp->object.position.x, temp->object.position.y, temp->object.position.y); 
   temp->object.position.y -= (float)new_position.x;
   temp->object.position.z -= (float)new_position.y;
  temp->object.position.x += x;
  printf("before : %f, %f, %f\n", temp->object.position.x, temp->object.position.y, temp->object.position.y);
  return (EXIT_SUCCESS);
}
