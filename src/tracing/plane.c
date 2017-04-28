/*
** intersect_plane.c for  in /home/NANAA/projets/raytracer1/intersect
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Feb 10 15:57:16 2017 Nathan Lebon
** Last update Fri Apr 28 13:48:24 2017 NANAA
*/

#include "raytracer.h"

float           intersect_plane(sfVector3f *dir_vector, sfVector3f *eye_pos, sfVector3f *object, float radius)
{
  float         k;

  object->x = object->x;
  radius = radius;
  if (dir_vector->x < 0)
    return (-1.0f);
  if (dir_vector->z == 0)
    return (-1.0f);
  k = (-(eye_pos->z) / dir_vector->z);
  if (k < 0)
    return (-1.0f);
  return (k);
}

/*
sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	new;

  new.x = 0.0f;
  new.y = 0.0f;
  new.z = 1.0f;
  return ((new));
  }*/
