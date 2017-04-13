/*
** misc.c for Project-Master in /home/NANAA/Projets/raytracer1/bonus
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Wed Mar 15 11:09:31 2017 NANAA
** Last update Fri Mar 17 16:18:53 2017 NANAA
*/

#include <math.h>
#include <SFML/Graphics/Color.h>
#include "include/ray.h"

sfColor		set_color(int type)
{
  sfColor	color;

  color.r = 0;
  color.g = 0;
  color.b = 0;
  color.a = 255;
  if (type == SPHERE)
    color.r = 255;
  else if (type == PLANE)
    color.b = 255 ;
  else if (type == CYL)
    color.g = 255;
  else if (type == CONE)
    {
      color.r = 255;
      color.g = 255;
    }
  return (color);
}
