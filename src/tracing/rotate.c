/*
** rotate.c for Project-Master in /home/NANAA/Projets/raytracer1/src
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Sun Mar 19 17:02:04 2017 NANAA
** Last update Tue May  9 13:37:43 2017 NANAA
*/

#include <math.h>
#include "raytracer.h"

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  float		r;
  sfVector3f	temp;

  r = M_PI / 180.0f;
  angles.x = angles.x * r;
  angles.y = angles.y * r;
  angles.z = angles.z * r;
  temp = to_rotate;
  to_rotate.x = temp.x;
  to_rotate.y = temp.y * cos(angles.x) - temp.z * sin(angles.x);
  to_rotate.z = temp.y * sin(angles.x) + temp.z * cos(angles.x);
  temp = to_rotate;
  to_rotate.x = temp.x * cos(angles.y) + temp.z * sin(angles.y);
  to_rotate.y = temp.y;
  to_rotate.z = - temp.x * sin(angles.y) + temp.z * cos(angles.y);
  temp = to_rotate;
  to_rotate.x = temp.x * cos(angles.z) + temp.y * -sin(angles.z);
  to_rotate.y = temp.x * sin(angles.z) + temp.y * cos(angles.z);
  to_rotate.z = temp.z;
  return (to_rotate);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  float		r;
  sfVector3f	temp;

  r = M_PI / 180.0f;
  angles.x = angles.x * r;
  angles.y = angles.y * r;
  angles.z = angles.z * r;
  temp = to_rotate;
  to_rotate.x = temp.x * cos(angles.z) + temp.y * - sin(angles.z);
  to_rotate.y = temp.x * sin(angles.z) + temp.y * cos(angles.z);
  to_rotate.z = temp.z;
  temp = to_rotate;
  to_rotate.x = temp.x * cos(angles.y) + temp.z * sin(angles.y);
  to_rotate.y = temp.y;
  to_rotate.z = - temp.x * sin(angles.y) + temp.z * cos(angles.y);
  temp = to_rotate;
  to_rotate.x = temp.x;
  to_rotate.y = temp.y * cos(angles.x) - temp.z * sin(angles.x);
  to_rotate.z = temp.y * sin(angles.x) + temp.z * cos(angles.x);
  return (to_rotate);
}
