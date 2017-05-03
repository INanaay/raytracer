/*
** main.c for Project-Master in /home/NANAA/Projets/raytracer2
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Apr 10 15:03:39 2017 NANAA
** Last update Wed May  3 14:06:15 2017 NANAA
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
  print_gui(&screen);
  // error = print_objects(&screen);
  //if (error)
  // return (EXIT_ERROR);
  //  my_put_pixel(&(screen.framebuffer), sfVector2i_create(200, 200), sfRed);
  show_window(&screen);
  if (error)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}
