/*
** calc_dir_vector.c for  in /home/NANAA/projets/raytracer1
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Feb 10 15:53:31 2017 Nathan Lebon
** Last update Tue Mar 28 11:23:21 2017 NANAA
*/

#include "include/ray.h"

int     my_strlen(char *s)
{
  int   i;

  if (s == NULL)
    return (0);
  i = 0;
  while (s[i])
    i++;
  return (i);
}

void    my_putstr(char *s)
{
  write(1, s, my_strlen(s));
}

sfVector3f      calc_dir_vector(t_eye *eye)
{
  sfVector3f    dir_vector;

  if ((eye->pos.x < 0 || eye->pos.x > eye->screen.x) ||
      (eye->pos.y < 0 || eye->pos.y > eye->screen.y))
    {
      my_putstr("wrong coordinates\n");
    }
  else
    {
      eye->dir_vector.x = FRAMEBUFFER_WIDTH;
      eye->dir_vector.y = (eye->screen.x / 2) - eye->pos.x;
      eye->dir_vector.z = (eye->screen.y / 2) - eye->pos.y;
      return (get_normal_vector(eye->dir_vector));
    }
}
