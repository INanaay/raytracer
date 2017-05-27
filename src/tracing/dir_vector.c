/*
** calc_dir_vector.c for  in /home/NANAA/projets/raytracer1
**
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Fri Feb 10 15:53:31 2017 Nathan Lebon
** Last update Sat May 27 11:47:26 2017 schwarzy
*/

#include "raytracer.h"

sfVector3f      calc_dir_vector(sfVector2i screen)
{
  sfVector3f    dir_vector;

  dir_vector.x = FRAMEBUFFER_DEFAULT_WIDTH;
  dir_vector.y = (FRAMEBUFFER_DEFAULT_WIDTH / 2) - screen.x;
  dir_vector.z = (FRAMEBUFFER_DEFAULT_HEIGHT / 2) - screen.y;
  return (get_normal_vector(dir_vector));
}
