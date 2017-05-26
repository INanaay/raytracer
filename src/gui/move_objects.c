/*
** move_objects.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Tue May  2 14:00:37 2017 NANAA
** Last update Fri May 26 15:06:49 2017 NANAA
*/

#include "raytracer.h"

sfVector2i	calc_new_pos(sfVector2i mouse_position, sfVector2i new_position)
{
  sfVector2i	move;

  move = sfVector2i_create(0, 0);
  if (new_position.x < FRAMEBUFFER_DEFAULT_WIDTH)
    {
      move.x = mouse_position.x - new_position.x;
      move.y = mouse_position.y - new_position.y;
    }
  return (move);
}

static float		move_x(float x)
{
  if (sfKeyboard_isKeyPressed(sfKeyPageDown))
    x -= 0.01;
  if (sfKeyboard_isKeyPressed(sfKeyPageUp))
    x += 0.01;
  return (x);
}

static void		get_new_pos(sfVector3f *obj_pos, sfVector2i *pos, float x)
{
  obj_pos->y += (float)pos->x;
  obj_pos->z += (float)pos->y;
  obj_pos->x += x;
}

int		move_objects(sfVector2i mouse_position, t_screen *screen)
{
  int		id;
  t_nodeObject	*temp;
  sfVector3f	dir_vector;
  sfVector2i	new_position;
  float		x;
  int		index;

  x = 0;
  while (sfMouse_isButtonPressed(sfMouseLeft))
    {
      new_position = sfMouse_getPositionRenderWindow(screen->window);
      x = move_x(x);
    }
  new_position = calc_new_pos(mouse_position, new_position);
  dir_vector = calc_dir_vector(mouse_position);
  dir_vector = apply_rotation(dir_vector, screen->rotate);
  id = find_nearest_intersect(&(screen->objects), &dir_vector,
			      &(screen->eyes));
  if (id == -1)
      return (EXIT_ERROR);
  temp = screen->objects.begin;
  index = 0;
  while (index++ != id)
    temp = temp->next;
  get_new_pos(&(temp->object.position), &new_position, x);
  screen->last_object = id;
  return (EXIT_SUCCESS);
}
