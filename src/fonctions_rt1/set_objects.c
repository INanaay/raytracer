/*
** set_objects.c for  in /home/NANAA/projets/raytracer1/bonus
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Tue Feb 28 16:04:28 2017 Nathan Lebon
** Last update Tue Mar 28 10:57:18 2017 NANAA
*/

#include <unistd.h>
#include "include/ray.h"

t_object **create_objs_tab(t_object **objs, int size)
{
  if ((objs = malloc(sizeof (t_object *) * (size + 2))) == NULL)
    return (NULL);
  objs[NB_OBJ + 1] = NULL;
  return (objs);
}

t_object	*set_object(int type, float radius)
{
  t_object	*obj;
  obj = malloc(sizeof (t_object));
  if (obj == NULL)
    return (NULL);
  obj->type = type;
  obj->radius = radius;
  return (obj);
}

t_object	*set_object_position(t_object *obj, float x, float y, float z)
{
  obj->x = x;
  obj->y = y;
  obj->z = z;
  return (obj);
}
