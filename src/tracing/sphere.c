/*
** intersect_sphere.c for  in /home/NANAA/projets/raytracer1/intersect
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Feb 10 15:55:52 2017 Nathan Lebon
** Last update Thu Apr 27 17:05:40 2017 NANAA
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

  a = (float)((pow(dir_vector->x, 2) + pow(dir_vector->y, 2))
              + pow(dir_vector->z, 2));
  b = 2 * (((eye_pos->x - object->x) * dir_vector->x)
	   + ((eye_pos->y - object->y) * dir_vector->y)
	   + ((eye_pos->z - object->z) * dir_vector->z));
  c = (float)(pow(eye_pos->x - object->x, 2)
	      + (pow(eye_pos->y - object->y, 2))
              + pow(eye_pos->z - object->z, 2) - pow(radius, 2));
  delt = pow(b, 2) - (4 * a * c);
  if (delt < 0)
    return (-1.0f);
  else
    return (get_root(a, b, delt));
}
/*
sfVector3f	get_normal_sphere(sfVector3f inter, float x, float y, float z)
{
  inter.x = inter.x - x;
  inter.y -= y;
  inter.z -= z;
  return (get_normal_vector(inter));
  }*/
