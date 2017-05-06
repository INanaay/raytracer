/*
** modify_objects.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Sat May  6 11:46:56 2017 NANAA
** Last update Sat May  6 12:22:04 2017 NANAA
*/

#include "raytracer.h"

int		modify_color(t_screen *screen, int button_id)
{
  t_nodeObject	*temp;

  if (screen->last_object == -1)
    return (EXIT_ERROR);
  temp = screen->objects.begin;
  while (temp->id != screen->last_object)
    temp = temp->next;
  if (button_id == 4 && temp->object.color.r > 0)
    temp->object.color.r -= 5;
  if (button_id == 5 && temp->object.color.r < 255)
    temp->object.color.r += 5;
  if (button_id == 6 && temp->object.color.g > 0)
    temp->object.color.g -= 5;
  if (button_id == 7 && temp->object.color.g < 255)
    temp->object.color.g += 5;
  if (button_id == 8 && temp->object.color.b > 0)
    temp->object.color.b -=5;
  if (button_id == 9 && temp->object.color.b < 255)
    temp->object.color.b += 5;
  return (EXIT_SUCCESS);
}
