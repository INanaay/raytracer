/*
** modify_objects.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Sat May  6 11:46:56 2017 NANAA
** Last update Fri May 12 11:51:15 2017 NANAA
*/

#include "raytracer.h"

int		change_damier(t_screen *screen)
{
  t_nodeObject	*temp;
  int		index;

  index = 0;
  if (screen->last_object == -1)
    return (EXIT_ERROR);
  temp = screen->objects.begin;
  while (index++ != screen->last_object)
    temp = temp->next;
  if (temp->object.is_damier == 1)
    temp->object.is_damier = 0;
  else
    temp->object.is_damier = 1;
  return (EXIT_SUCCESS);
}

int		modify_color(t_screen *screen, int button_id)
{
  t_nodeObject	*temp;
  int		index;

  index = 0;
  if (screen->last_object == -1)
    return (EXIT_ERROR);
  temp = screen->objects.begin;
  while (index++ != screen->last_object)
    temp = temp->next;
  if (button_id == 3 && temp->object.color.r > 0)
    temp->object.color.r -= 5;
  if (button_id == 4 && temp->object.color.r < 255)
    temp->object.color.r += 5;
  if (button_id == 6 && temp->object.color.g > 0)
    temp->object.color.g -= 5;
  if (button_id == 7 && temp->object.color.g < 255)
    temp->object.color.g += 5;
  if (button_id == 9 && temp->object.color.b > 0)
    temp->object.color.b -=5;
  if (button_id == 10 && temp->object.color.b < 255)
    temp->object.color.b += 5;
  return (EXIT_SUCCESS);
}
