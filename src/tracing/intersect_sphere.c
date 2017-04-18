/*
** intersect_sphere.c for  in /home/NANAA/projets/raytracer1/intersect
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Feb 10 15:55:52 2017 Nathan Lebon
** Last update Tue Apr 18 10:55:26 2017 NANAA
*/

#include "raytracer.h"

float           get_root(float a, float b, float delt)
{
  float         r1;
  float         r2;

  if (delt == 0)
    {
      r1 = (-b) / (2 * a);
      return (r1);
    }
  else
    {
      r1 = (-b + (float)sqrt(delt)) / (2 * a);
      r2 = (-b - (float)sqrt(delt)) / (2 * a);
      if (r1 > r2)
	return (r2);
      return (r1);
    }
}

float           intersect_sphere(t_eye *eye, float radius, t_object *obj)
{
  float         a;
  float         b;
  float         c;
  float         delt;
  float         r1;
  float         r2;

  a = (float)((pow(eye->dir_vector.x, 2) + pow(eye->dir_vector.y, 2))
              + pow(eye->dir_vector.z, 2));
  b = 2 * (((eye->eye_pos.x - obj->x) * eye->dir_vector.x)
	   + ((eye->eye_pos.y - obj->y) * eye->dir_vector.y)
	   + ((eye->eye_pos.z - obj->z) * eye->dir_vector.z));
  c = (float)(pow(eye->eye_pos.x - obj->x, 2)
	      + (pow(eye->eye_pos.y - obj->y, 2))
              + pow(eye->eye_pos.z - obj->z, 2) - pow(radius, 2));
  delt = pow(b, 2) - (4 * a * c);
  if (delt < 0)
    return (-1.0f);
  else
    return (get_root(a, b, delt));
}

sfVector3f	get_normal_sphere(sfVector3f inter, float x, float y, float z)
{
  inter.x = inter.x - x;
  inter.y -= y;
  inter.z -= z;
  return (get_normal_vector(inter));
}
