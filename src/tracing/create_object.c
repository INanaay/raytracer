/*
** create_object.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Tue Apr 25 11:15:33 2017 NANAA
** Last update Thu Apr 27 15:27:37 2017 NANAA
*/

#include "raytracer.h"
#include "libmy.h"

t_object	init_object(int type)
{
  t_object	new_object;

  new_object.type = type;
  new_object.position = sfVector3f_create(0, 0, 0);
  new_object.color = sfRed;
  if (type == plane)
    new_object.value = 0;
  else
    new_object.value = 40;
  new_object.is_transparent = false;
  new_object.is_mirror = false;
  if (type == sphere)
    new_object.intersect = &intersect_sphere;
  else if (type == plane)
    new_object.intersect = &intersect_plane;
  else if (type == cyl)
    new_object.intersect = &intersect_cyl;
  else
    new_object.intersect = &intersect_cone;
  return (new_object);
}
  
