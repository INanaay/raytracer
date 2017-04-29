/*
** intersect_sphere.c for  in /home/NANAA/projets/raytracer1/intersect
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Feb 10 15:55:52 2017 Nathan Lebon
** Last update Sat Apr 29 16:30:10 2017 NANAA
*/

#include <math.h>
#include "raytracer.h"

float           intersect_cone(sfVector3f *dir_vector, sfVector3f *eye_pos, sfVector3f *object, float radius)
{
  float         a;
  float         b;
  float         c;
  float         delt;
  float		tana;

  /* NEED TO USE OBJ POS */
  
  tana = tan(radius) * tan(radius);
  a = (float)((pow(dir_vector->x, 2) + pow(dir_vector->y, 2))
              - tana * pow(dir_vector->z, 2));
  b = 2 * ((eye_pos->x * dir_vector->x)
	   + (eye_pos->y * dir_vector->y) - tana
	   * (eye_pos->z * dir_vector->z));
  c = (float)(pow(eye_pos->x, 2) + (pow(eye_pos->y, 2))
              - tana * pow(eye_pos->z, 2));
  delt = pow(b, 2) - (4 * a * c);
  if (delt < 0)
    return (-1.0f);
  else
    return (get_root(a, b, delt));
}

sfVector3f	get_normal_cone(sfVector3f intersection_point, sfVector3f *obj, int value)
{
  sfVector3f	temp;
  float		rad;

  value = value;
  rad = (intersection_point.x * M_PI) / 180;
  temp.x -= obj->x;
  temp.y -= obj->y;
  temp.z = -(intersection_point.z - obj->z) * cos(rad);
  return (get_normal_vector(intersection_point));
}
