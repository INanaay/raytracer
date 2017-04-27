/*
** intersect_cyl.c for  in /home/NANAA/projets/raytracer1
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Feb 10 16:56:27 2017 Nathan Lebon
** Last update Thu Apr 27 12:17:29 2017 NANAA
*/

#include "raytracer.h"

float		intersect_cyl(sfVector3f *dir_vector, sfVector3f *eye_pos, sfVector3f *obj, float radius)
{
  float		a;
  float		b;
  float		c;
  float		delt;

  a = dir_vector->x * dir_vector->x + dir_vector->y
    * dir_vector->y;
  b = 2 * dir_vector->x * (eye_pos->x - obj->x) + 2
    * dir_vector->y * (eye_pos->y - obj->y);
  c = (eye_pos->x - obj->x) * (eye_pos->x - obj->x)
    + (eye_pos->y - obj->y) * (eye_pos->y - obj->y) - radius * radius;
  delt = (b * b) - (4 * a * c);
  return (get_root(a, b, delt));
}

sfVector3f	get_normal_cylinder(sfVector3f inter)
{
  inter.z = 0;
  return (inter);
}
