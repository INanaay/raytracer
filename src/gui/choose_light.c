/*
** choose_light.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon May 15 10:33:58 2017 NANAA
** Last update Mon May 15 11:01:28 2017 NANAA
*/

#include "raytracer.h"

void		change_light(t_screen *screen)
{
  if (sfKeyboard_isKeyPressed(sfKeyNum1))
    screen->current_light = 0;
  if (sfKeyboard_isKeyPressed(sfKeyNum2))
    screen->current_light = 1;
  if (sfKeyboard_isKeyPressed(sfKeyNum3))
    screen->current_light = 2;
}
