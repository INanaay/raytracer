/*
** main.c for Project-Master in /home/NANAA/Projets/raytracer2
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Apr 10 15:03:39 2017 NANAA
** Last update Mon Apr 10 19:15:34 2017 NANAA
*/

#include "raytracer.h"

sfRenderWindow *init_window(t_my_framebuffer *framebuffer)
{
  *framebuffer = my_create_framebuffer(FRAMEBUFFER_DEFAULT_WIDTH, FRAMEBUFFER_DEFAULT_HEIGHT);
  if (framebuffer == NULL)
    return (NULL);
  return (my_create_window(NAME, WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT));
}

int		      	 main()
{
  framebuffer		framebuffer;
  t_screen		screen;
  sfRenderWindow	*window;

  window = init_window(&framebuffer);
  if (window == NULL)
    return (84);
  my_show_window(window, &framebuffer);
}
