/*
** intersect_sphere.c for  in /home/NANAA/projets/raytracer1/intersect
**
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Fri Feb 10 15:55:52 2017 Nathan Lebon
** Last update Sat May 27 12:25:53 2017 schwarzy
*/

#include <math.h>
#include "libmy.h"
#include "raytracer.h"

float           intersect_sphere(sfVector3f *dir_vector, sfVector3f *eye_pos,
				 sfVector3f *object, float radius)
{
  float         a;
  float         b;
  float         c;
  float         delt;

  a = powf(dir_vector->x, 2) + powf(dir_vector->y, 2) + powf(dir_vector->z, 2);
  b = 2 * (((eye_pos->x - object->x) * dir_vector->x)
	   + ((eye_pos->y - object->y) * dir_vector->y)
	   + ((eye_pos->z - object->z) * dir_vector->z));
  c = powf(eye_pos->x - object->x, 2)
	      + (powf(eye_pos->y - object->y, 2))
              + powf(eye_pos->z - object->z, 2) - powf(radius, 2));
  delt = powf(b, 2) - (4 * a * c);
  if (delt < 0.0f)
    return (-1.0f);
  else
    return (get_root(a, b, delt));
}

sfVector3f	get_normal_sphere(sfVector3f inter, sfVector3f *obj_pos,
				  int value)
{
  value = value;
  inter.x -= obj_pos->x;
  inter.y -= obj_pos->y;
  inter.z -= obj_pos->z;
  return (get_normal_vector(inter));
}
