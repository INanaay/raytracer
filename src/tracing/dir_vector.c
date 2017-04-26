/*
** calc_dir_vector.c for  in /home/NANAA/projets/raytracer1
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Feb 10 15:53:31 2017 Nathan Lebon
** Last update Wed Apr 26 11:35:50 2017 NANAA
*/

#include "raytracer.h"


sfVector3f      calc_dir_vector(sfVector3f eye_pos, sfVector2i screen_pos)
{
  sfVector3f    dir_vector;

  dir_vector.x = FRAMEBUFFER_DEFAULT_WIDTH;
  dir_vector.y = (screen_pos.x / 2) - eye_pos.x;
  dir_vector.z = (screen_pos.y / 2) - eye_pos.y;
  return (get_normal_vector(dir_vector));
}
