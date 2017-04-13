/*
** light.c for  in /home/NANAA/projets/raytracer1/bonus
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Wed Mar  1 13:26:15 2017 Nathan Lebon
** Last update Wed Mar 15 16:57:49 2017 NANAA
*/

#include "include/ray.h"

sfVector3f	get_normalized_object(sfVector3f inter, t_object *obj)
{
  if (obj->type == SPHERE)
    inter = get_normal_sphere(inter, obj->x, obj->y, obj->z);
  else if (obj->type == PLANE)
    inter = get_normal_plane(1);
  else if (obj->type == CYL)
    inter = get_normal_cylinder(inter);
  else if (obj->type == CONE)
    inter = get_normal_cone(inter, obj);
  return (inter);
}

sfVector3f	get_inter_point(t_eye *eye, float dist)
{
  sfVector3f	new;

  new.x = eye->eye_pos.x + dist * eye->dir_vector.x;
  new.y = eye->eye_pos.y + dist * eye->dir_vector.y;
  new.z = eye->eye_pos.z + dist * eye->dir_vector.z;
  return (new);
}

sfVector3f	light_vector(t_eye *eye, sfVector3f light_pos, float dist)
{
  sfVector3f	light;

  light.x = light_pos.x - (eye->eye_pos.x + dist * eye->dir_vector.x);
  light.y = light_pos.y - (eye->eye_pos.y + dist * eye->dir_vector.y);
  light.z = light_pos.z - (eye->eye_pos.z + dist * eye->dir_vector.z);
  return (light);
}

sfVector3f	get_normal_vector(sfVector3f vector)
{
  float		norm;

  norm = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
  vector.x = vector.x / norm;
  vector.y = vector.y / norm;
  vector.z = vector.z / norm;
  return (vector);
}

float		get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
 {
  float		cosa;

  cosa = normal_vector.x * light_vector.x + normal_vector.y * light_vector.y
    + normal_vector.z * light_vector.z;
  if (cosa > 0 && cosa < 1)
    return (cosa);
  return (0);
}
