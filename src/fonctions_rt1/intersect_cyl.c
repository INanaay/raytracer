/*
** intersect_cyl.c for  in /home/NANAA/projets/raytracer1
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Feb 10 16:56:27 2017 Nathan Lebon
** Last update Fri Mar 17 13:25:43 2017 NANAA
*/

#include "include/ray.h"

float		intersect_cyl(t_eye *eye, float radius, t_object *obj)
{
  float		a;
  float		b;
  float		c;
  float		delt;

  a = eye->dir_vector.x * eye->dir_vector.x + eye->dir_vector.y
    * eye->dir_vector.y;
  b = 2 * eye->dir_vector.x * (eye->eye_pos.x - obj->x) + 2
    * eye->dir_vector.y * (eye->eye_pos.y - obj->y);
  c = (eye->eye_pos.x - obj->x) * (eye->eye_pos.x - obj->x)
    + (eye->eye_pos.y - obj->y) * (eye->eye_pos.y - obj->y) - radius * radius;
  delt = (b * b) - (4 * a * c);
  return (get_root(a, b, delt));
}

sfVector3f	get_normal_cylinder(sfVector3f inter)
{
  inter.z = 0;
  return (get_normal_vector(inter));
}
