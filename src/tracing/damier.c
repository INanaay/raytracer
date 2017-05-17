/*
** damier.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Wed May 10 10:59:12 2017 NANAA
** Last update Wed May 17 11:16:11 2017 anatole zeyen
*/

#include "raytracer.h"

void		damier(sfVector3f *inter, sfColor *color)
{
  int		x;
  int		y;
  int		z;

  x = inter->x / SLAB_SIZE;
  y = inter->y / SLAB_SIZE;
  z = inter->z / SLAB_SIZE;
  if (x % 2 == 0)
    {
      if ((y % 2 == 0 && z % 2 == 0) || (y % 2 != 0 && z % 2 != 0))
	*color = sfWhite;
      else
	*color = sfBlack;
    }
  else
    {
      if ((y % 2 != 0 && z % 2 != 0) ||
	  (y % 2 == 0 && z % 2 == 0))
	*color = sfBlue;
      else
	*color = sfRed;
    }
}
