/*
** main.c for Project-Master in /home/NANAA/Projets/raytracer2
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Mon Apr 10 15:03:39 2017 NANAA
** Last update Sun May 28 18:59:19 2017 schwarzy
*/

#include "raytracer.h"

int			 main(int argc, char **argv)
{
  int			error;
  t_screen		screen;

  error = init_screen(&screen);
  if (error)
    return (EXIT_ERROR);
  if (argc == 2)
    {
      error = deserialize(&screen, argv[1]);
      if (error == -1)
	return (EXIT_ERROR);
    }
  print_gui(&screen);
  show_window(&screen);
  if (error)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}
