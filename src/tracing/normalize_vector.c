/*
** normalize_vector.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Wed Apr 26 11:21:00 2017 NANAA
** Last update Thu Apr 27 16:21:56 2017 NANAA
*/

#include <math.h>
#include "raytracer.h"

sfVector3f	get_normal_vector(sfVector3f vector)
{
  float		norm;

  norm = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
  vector.x = vector.x / norm;
  vector.y = vector.y / norm;
  vector.z = vector.z / norm;
  return (vector);
}
