/*
** intersect_sphere.c for  in /home/NANAA/projets/raytracer1/intersect
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Feb 10 15:55:52 2017 Nathan Lebon
** Last update Mon Mar 13 13:06:07 2017 NANAA
*/

#include "include/ray.h"

float           intersect_cone(t_eye *eye, float radius)
{
  float         a;
  float         b;
  float         c;
  float         delt;
  float         r1;
  float         r2;
  float		tana;

  tana = tan(radius) * tan(radius);
  a = (float)((pow(eye->dir_vector.x, 2) + pow(eye->dir_vector.y, 2))
              - tana * pow(eye->dir_vector.z, 2));
  b = 2 * ((eye->eye_pos.x * eye->dir_vector.x)
	   + (eye->eye_pos.y * eye->dir_vector.y) - tana
	   * (eye->eye_pos.z * eye->dir_vector.z));
  c = (float)(pow(eye->eye_pos.x, 2) + (pow(eye->eye_pos.y, 2))
              - tana * pow(eye->eye_pos.z, 2));
  delt = pow(b, 2) - (4 * a * c);
  if (delt < 0)
    return (-1.0f);
  else
    return (get_root(a, b, delt));
}

sfVector3f	get_normal_cone(sfVector3f intersection_point, t_object *obj)
{
  sfVector3f	temp;
  float		rad;

  rad = (obj->radius * M_PI) / 180;
  intersection_point.x -=  obj->x;
  intersection_point.y -= obj->y;
  intersection_point.z = -(intersection_point.z - obj->z) * cos(rad);
  return (get_normal_vector(intersection_point));
}
