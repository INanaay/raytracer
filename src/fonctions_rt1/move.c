/*
** move.c for  in /home/NANAA/projets/raytracer1/bonus
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Wed Mar  1 15:03:18 2017 Nathan Lebon
** Last update Wed Mar 15 17:27:39 2017 NANAA
*/

#include "include/ray.h"

int	move_object(t_eye *eye)
{
  int	moved;

  moved = 1;
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    eye->eye_pos.y += 2;
  else if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    eye->eye_pos.y -= 2;
  else if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
    eye->eye_pos.z += 2;
  else  if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
    eye->eye_pos.z -= 2;
  else if (sfKeyboard_isKeyPressed(sfKeyPageDown))
    eye->eye_pos.x -= 10;
  else if (sfKeyboard_isKeyPressed(sfKeyPageUp))
    eye->eye_pos.x += 10;
  else
    moved = 0;
  return (moved);
}

int	move_light(t_eye *eye)
{
  int	moved;

  moved = 1;
  if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue)
      eye->light_pos.y += 10;
  else if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue)
      eye->light_pos.y-= 10;
  else if (sfKeyboard_isKeyPressed(sfKeyW) == sfTrue)
      eye->light_pos.z += 10;
  else if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
    eye->light_pos.z -= 10;
  else if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
    eye->light_pos.x += 20;
  else if (sfKeyboard_isKeyPressed(sfKeyX) == sfTrue)
    eye->light_pos.x -= 10;
  else
    moved = 0;
  return (moved);
}
