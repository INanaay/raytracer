/*
** calc_dir_vector.c for  in /home/NANAA/projets/raytracer1
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Feb 10 15:53:31 2017 Nathan Lebon
** Last update Thu Apr 27 16:03:33 2017 NANAA
*/

#include "raytracer.h"


sfVector3f      calc_dir_vector(sfVector3f eye_pos, sfVector2i screen)
{
  sfVector3f    dir_vector;

  dir_vector.x = FRAMEBUFFER_DEFAULT_WIDTH;
  dir_vector.y = (FRAMEBUFFER_DEFAULT_WIDTH / 2) - eye_pos.x;
  dir_vector.z = (FRAMEBUFFER_DEFAULT_HEIGHT / 2) - eye_pos.y;
  return (get_normal_vector(dir_vector));
}
