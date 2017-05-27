/*
** create_object.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Tue Apr 25 11:15:33 2017 NANAA
** Last update Sat May 27 17:44:49 2017 schwarzy
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
  new_object.position = sfVector3f_create(0, 0, 40);
  new_object.rotation = sfVector3f_create(0, 0, 0);
  new_object.color = sfRed;
  new_object.spec = 1.0f;
  new_object.lim = 20.0;
  new_object.limited = false;
  new_object.is_damier = false;
  if (type == plane)
    {
      new_object.value = 0;
      new_object.position.z = 0;
      new_object.is_damier = true;
    }
  else if (type == cyl)
    {
      new_object.limited = true;
      new_object.value = 20;
    }
  else
    new_object.value = 40;
  set_object(&new_object, type);
  return (new_object);
}
