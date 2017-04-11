/*
** tools.c for Project-Master in /home/NANAA/Projets/raytracer2/src
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Tue Apr 11 15:31:44 2017 NANAA
** Last update Tue Apr 11 15:42:04 2017 NANAA
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
}
