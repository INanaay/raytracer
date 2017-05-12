/*
** create_object.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Tue Apr 25 11:15:33 2017 NANAA
** Last update Fri May 12 12:18:57 2017 NANAA
*/

#include "raytracer.h"
#include "libmy.h"

void		set_object(t_object *object, int type)
{
  if (type == sphere)
    {
      object->intersect = &intersect_sphere;
      object->normal = &get_normal_sphere;
    }
  else if (type == plane)
    {
      object->intersect = &intersect_plane;
      object->normal = &get_normal_plane;
    }
  else if (type == cyl)
    {
      object->intersect = &intersect_cyl;
      object->normal = &get_normal_cylinder;
    }
  else
    {
      object->intersect = &intersect_cone;
      object->normal = &get_normal_cone;
    }
}

t_object	init_object(int type)
{
  t_object	new_object;

  new_object.type = type;
  new_object.position = sfVector3f_create(0, 0, 10);
  new_object.rotation = sfVector3f_create(0, 0 ,0);
  new_object.color = sfRed;
  if (type == plane)
    new_object.value = 0;
  else
    new_object.value = 40;
  new_object.is_transparent = false;
  new_object.is_mirror = false;
  if (type == plane)
    new_object.is_damier = true;
  else
    new_object.is_damier = false;
  set_object(&new_object, type);
  return (new_object);
}
  
