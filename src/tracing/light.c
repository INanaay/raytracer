/*
** light.c for  in /home/NANAA/projets/raytracer1/bonus
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Wed Mar  1 13:26:15 2017 Nathan Lebon
** Last update Mon May  1 11:30:54 2017 NANAA
*/

#include "raytracer.h"
/*
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
}*/

sfVector3f	get_inter_point(sfVector3f *eye_pos, sfVector3f *dir_vector, float dist)
{
  sfVector3f	new;
  
  new.x = eye_pos->x + dist * dir_vector->x;
  new.y = eye_pos->y + dist * dir_vector->y;
  new.z = eye_pos->z + dist * dir_vector->z;
  return (new);
}

sfVector3f	get_light_vector(sfVector3f *eye_pos, sfVector3f *dir_vector,
			     sfVector3f *light_pos, float dist)
{
  sfVector3f	light;
  sfVector3f	inter_point;

  inter_point = get_inter_point(&(*eye_pos), &(*dir_vector), dist);
  light.x = light_pos->x - inter_point.x;
  light.y = light_pos->y - inter_point.y;
  light.z = light_pos->z - inter_point.z;
  return (light);
}

float		get_light_coef(sfVector3f *light_vector, sfVector3f *normal_vector)
 {
  float		cosa;

  cosa = normal_vector->x * light_vector->x + normal_vector->y * light_vector->y
    + normal_vector->z * light_vector->z;
  if (cosa > 0 && cosa < 1)
    return (cosa);
  return (0);
}
