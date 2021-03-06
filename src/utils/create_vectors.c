/*
** tools.c for Project-Master in /home/NANAA/Projets/raytracer2/src
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Tue Apr 11 15:31:44 2017 NANAA
** Last update Sat May 27 12:56:59 2017 NANAA
*/

#include "raytracer.h"

sfVector3f	sfVector3f_create(float x, float y, float z)
{
  sfVector3f	new;

  new.x = x;
  new.y = y;
  new.z = z;
  return (new);
}

sfVector2i	sfVector2i_create(int x, int y)
{
  sfVector2i	new;

  new.x = x;
  new.y = y;
  return (new);
}

sfVector2f	sfVector2f_create(float x, float y)
{
  sfVector2f	new;

  new.x = x;
  new.y = y;
  return (new);
}

sfVector3f	sfVector3f_cpy(sfVector3f src)
{
  sfVector3f	new;

  new.x = src.x;
  new.y = src.y;
  new.z = src.z;
  return (new);
}
