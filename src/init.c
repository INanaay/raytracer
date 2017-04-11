/*
** init.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Tue Apr 11 11:36:42 2017 flavian gontier
** Last update Tue Apr 11 14:54:28 2017 anatole zeyen
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "raytracer.h"

int		init_framebuffer(t_my_framebuffer *buffer)
{
  size_t	buffer_size;

  buffer->dimensions.x = WINDOW_DEFAULT_WIDTH;
  buffer->dimensions.y = WINDOW_DEFAULT_HEIGHT;
  buffer_size = WINDOW_DEFAULT_WIDTH * WINDOW_DEFAULT_HEIGHT;
  buffer->pixels = my_calloc(sizeof(sfUint8) * buffer_size);
  if (buffer->pixels == NULL)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}

int		init_screen(t_screen *screen)
{
  int		error;
  sfVector3f	eyes;
  sfVector2i	dimensions;

  eyes = my_vector3f(EYES_DEFAULT_X, EYES_DEFAULT_Y, EYES_DEFAULT_Z);
  dimensions = my_vector2i(WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT);
  screen->eyes = eyes;
  screen->dimensions = dimensions;
  screen->objects_count = 0;
  screen->lights_count = 0;
  error = init_framebuffer(screen->framebuffer);
  screen->win = my_create_window("raytracer2", WINDOW_DEFAULT_WIDTH,
				 WINDOW_DEFAULT_HEIGHT);
  if (error)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}

int		load_screen(t_screen *screen, char *filepath)
{
  int		fd;
  int		bytes;

  fd = open(filepath, O_RDONLY);
  if (fd == -1)
    return (EXIT_ERROR);
  bytes = read(fd, screen, sizeof(t_screen));
  if (bytes != sizeof(t_screen))
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}
