/*
** create_vectors.c for  in /home/anatole.zeyen/raytracer2/src/utils
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Tue Apr 11 14:24:07 2017 anatole zeyen
** Last update Tue Apr 11 14:54:52 2017 anatole zeyen
*/

#include "raytracer.h"

sfVector3f	my_vector3f(float x, float y , float z)
{
  sfVector3f	to_return;

  to_return.x = x;
  to_return.y = y;
  to_return.z = z;
  return (to_return);
}

sfVector2f	my_vector2f(float x, float y)
{
  sfVector2f	to_return;

  to_return.x = x;
  to_return.y = y;
  return (to_return);
}

sfVector2i	my_vector2i(int x, int y)
{
  sfVector2i	to_return;

  to_return.x = x;
  to_return.y = y;
  return (to_return);
}
