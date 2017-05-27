/*
** intersect_sphere.c for  in /home/NANAA/projets/raytracer1/intersect
**
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Fri Feb 10 15:55:52 2017 Nathan Lebon
** Last update Sat May 27 11:42:14 2017 schwarzy
*/

#include <math.h>
#include "raytracer.h"

float           intersect_cone(sfVector3f *dir_vector, sfVector3f *eye_pos,
			       sfVector3f *object, float radius)
{
  float         a;
  float         b;
  float         c;
  float         delt;
  float		tana;

  tana = tan(radius) * tan(radius);
  a = (powf(dir_vector->x, 2) + powf(dir_vector->y, 2)
              - tana * powf(dir_vector->z, 2));
  b = 2 * (((eye_pos->x - object->x) * dir_vector->x)
	   + ((eye_pos->y - object->y) * dir_vector->y) - tana
	   * ((eye_pos->z - object->z) * dir_vector->z));
  c = powf(eye_pos->x - object->x, 2) + (powf(eye_pos->y - object->y, 2))
              - tana * powf(eye_pos->z - object->z, 2);
  delt = powf(b, 2) - (4 * a * c);
  if (delt < 0)
    return (-1.0f);
  else
    return (get_root(a, b, delt));
}

sfVector3f	get_normal_cone(sfVector3f intersection_point,
				sfVector3f *obj, int value)
{
  sfVector3f	temp;
  float		rad;

  temp = intersection_point;
  value = value;
  rad = (intersection_point.x * M_PI) / 180;
  temp.x -= obj->x;
  temp.y -= obj->y;
  temp.z = -(intersection_point.z - obj->z) * cos(rad);
  return (get_normal_vector(intersection_point));
}
