/*
** min.c for Project-Master in /home/NANAA/Projets/raytracer1/bonus
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Fri Mar 10 10:49:53 2017 NANAA
** Last update Sat Mar 11 11:56:45 2017 NANAA
*/

#include "include/ray.h"

int	get_min_inter_place(t_object **objs)
{
  int	i;
  float	min;
  int	place;
  int	*tab;

  i = 0;
  place = 0;
  min = 100000;
  while (objs[i])
    {
      if (objs[i]->inter < min && objs[i]->inter > 0)
	{
	  place = i;
	  min = objs[i]->inter;
	}
      i++;
    }
  return (place);
}
