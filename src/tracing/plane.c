/*
** intersect_plane.c for  in /home/NANAA/projets/raytracer1/intersect
**
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Fri Feb 10 15:57:16 2017 Nathan Lebon
** Last update Mon May 22 16:28:53 2017 schwarzy
*/

#include "raytracer.h"

float           intersect_plane(sfVector3f *dir_vector, sfVector3f *eye_pos,
				sfVector3f *object, float radius)
{
  float         k;

  radius = radius;
  if (dir_vector->x < 0.0f || dir_vector->z == 0.0f)
    return (-1.0f);
  k = - (eye_pos->z / dir_vector->z);
  if (k < 0.0f)
    return (-1.0f);
  return (k);
}

sfVector3f	get_normal_plane(sfVector3f inter, sfVector3f *pos, int value)
{
  sfVector3f	new;

  value = value;
  pos = pos;
  inter = inter;
  new.x = 0.0f;
  new.y = 0.0f;
  new.z = 1.0f;
  return ((new));
}
