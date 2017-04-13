/*
** intersect_plane.c for  in /home/NANAA/projets/raytracer1/intersect
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Feb 10 15:57:16 2017 Nathan Lebon
** Last update Fri Mar 17 16:10:17 2017 NANAA
*/

#include "include/ray.h"

float           intersect_plane(t_eye *eye)
{
  float         k;

  if (eye->dir_vector.x < 0)
    return (-1.0f);
  if (eye->dir_vector.z == 0)
    return (-1.0f);
  k = (-(eye->eye_pos.z) / eye->dir_vector.z);
  if (k < 0)
    return (-1.0f);
  return (k);
}

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	new;

  new.x = 0.0f;
  new.y = 0.0f;
  new.z = 1.0f;
  return ((new));
}
