/*
** handle_movements.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Tue May  9 13:58:40 2017 NANAA
** Last update Fri May 12 12:36:55 2017 NANAA
*/

#include "raytracer.h"

int	move_eye(sfVector3f *eyes)
{
  bool	moved;

  moved = true;
  if (sfKeyboard_isKeyPressed(sfKeyLeft))
    eyes->y += 2;
  else if (sfKeyboard_isKeyPressed(sfKeyRight))
    eyes->y -= 2;
  else if (sfKeyboard_isKeyPressed(sfKeyUp))
    eyes->z += 2;
  else if (sfKeyboard_isKeyPressed(sfKeyDown))
    eyes->z -= 2;
  else if (sfKeyboard_isKeyPressed(sfKeyPageDown))
    eyes->x -= 10;
  else if (sfKeyboard_isKeyPressed(sfKeyPageUp))
    eyes->x += 10;
  else
    moved = false;
  return (moved);
}

int	move_rotate(sfVector3f *rotate)
{
  bool	moved;

  moved = true;
  if (sfKeyboard_isKeyPressed(sfKeyLControl) && (sfKeyboard_isKeyPressed(sfKeyLeft)))
    rotate->z += 1;
  else if (sfKeyboard_isKeyPressed(sfKeyLControl) && (sfKeyboard_isKeyPressed(sfKeyRight)))
    rotate->z -= 1;
  else if (sfKeyboard_isKeyPressed(sfKeyLControl) && (sfKeyboard_isKeyPressed(sfKeyUp)))
    rotate->y += 1;
  else if (sfKeyboard_isKeyPressed(sfKeyLControl) && (sfKeyboard_isKeyPressed(sfKeyDown)))
    rotate->y -= 1;
  else
    moved = false;
  return (moved);
}

int	move_translate(sfVector3f *translate)
{
  int	moved;

  moved = true;
  if (sfKeyboard_isKeyPressed(sfKeyLShift) && (sfKeyboard_isKeyPressed(sfKeyUp)))
    translate->z += 0.1;
  else if (sfKeyboard_isKeyPressed(sfKeyLShift) && (sfKeyboard_isKeyPressed(sfKeyDown)))
    translate->z -= 0.1;
  else if (sfKeyboard_isKeyPressed(sfKeyLShift) && (sfKeyboard_isKeyPressed(sfKeyLeft)))
    translate->y += 0.1;
  else if (sfKeyboard_isKeyPressed(sfKeyLShift) && (sfKeyboard_isKeyPressed(sfKeyRight)))
    translate->y -= 0.1;
  else
    moved = false;
  return (moved);
}

int	move_light(t_screen *screen)
{
  int	i;
  bool	moved;

  moved = true;
  i = screen->current_light;
  if (sfKeyboard_isKeyPressed(sfKeyA))
    screen->lights[i].coordinates.y -= 10;
  else if (sfKeyboard_isKeyPressed(sfKeyD))
    screen->lights[i].coordinates.y += 10;
  else if (sfKeyboard_isKeyPressed(sfKeyW))
    screen->lights[i].coordinates.z += 10;
  else if (sfKeyboard_isKeyPressed(sfKeyS))
    screen->lights[i].coordinates.z -= 10;
  else if (sfKeyboard_isKeyPressed(sfKeyZ))
    screen->lights[i].coordinates.x += 20;
  else if (sfKeyboard_isKeyPressed(sfKeyX))
    screen->lights[i].coordinates.x -= 20;
  else
    moved = 0;
  return (moved);
}

int	handle_movements(t_screen *screen)
{
  bool	moved;
  
  moved = false;
  if ((moved = move_rotate(&screen->rotate)) == true)
    return (MOVED);
  if ((moved = move_translate(&screen->translate)) == true)
    return (MOVED);
  if ((moved = move_eye(&screen->eyes)) == true)
    return (MOVED);
  if ((moved = move_light(&(*screen))) == true)
    return (MOVED);
  return (false);
}
