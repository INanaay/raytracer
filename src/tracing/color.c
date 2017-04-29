/*
** color.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Sat Apr 29 16:14:21 2017 NANAA
** Last update Sat Apr 29 16:24:11 2017 NANAA
*/

# include <SFML/Graphics/Color.h>

sfColor		create_color(int r, int g, int b, int alpha)
{
  sfColor	color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = alpha;
  return (color);
}
