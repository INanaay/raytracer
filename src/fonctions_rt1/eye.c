/*
** eye.c for  in /home/NANAA/projets/raytracer1/bonus
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Tue Feb 28 16:59:31 2017 Nathan Lebon
** Last update Thu Mar  9 11:15:21 2017 NANAA
*/

#include "include/ray.h"

t_eye	*set_eye(t_eye *eye, int x, int y, int z)
{
  if ((eye = malloc(sizeof (t_eye))) == NULL)
    return (NULL);
  eye->eye_pos.x = x;
  eye->eye_pos.y = y;
  eye->eye_pos.z = z;
  eye->screen.x = FRAMEBUFFER_WIDTH;
  eye->screen.y = FRAMEBUFFER_HEIGHT;
  return (eye);
}

t_eye	*set_light(t_eye *eye, int x, int y, int z)
{
  eye->light_pos.x = x;
  eye->light_pos.y = y;
  eye->light_pos.z = z;
  return (eye);
}
