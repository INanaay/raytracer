/*
** main.c for Project-Master in /home/NANAA/Projets/raytracer2
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Apr 10 15:03:39 2017 NANAA
** Last update Wed Apr 12 12:14:28 2017 anatole zeyen
*/

#include "raytracer.h"

int			 main(int argc, char **argv)
{
  int			error;
  t_screen		screen;

  //  if (argc >= 2)
  // error = load_screen(&screen, argv[1]);
  //else
  error = init_screen(&screen);
  if (error)
    return (EXIT_ERROR);
  //  error = print_gui(&screen);
  //if (error)
  // return (EXIT_ERROR);
  
  // error = print_objects(&screen);
  //if (error)
  // return (EXIT_ERROR);
  error = show_window(&screen.window, &screen.framebuffer);
  if (error)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}
