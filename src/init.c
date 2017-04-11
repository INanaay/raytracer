/*
** init.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Tue Apr 11 11:36:42 2017 flavian gontier
** Last update Tue Apr 11 11:54:50 2017 flavian gontier
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "raytracer.h"

static int	init_framebuffer(framebuffer *buffer)
{
  size_t	buffer_size;

  buffer->dimensions.x = SCREEN_DEFAULT_WIDTH;
  buffer->dimensions.y = SCREEN_DEFAULT_HEIGHT;
  buffer_size = SCREEN_DEFAULT_WIDTH * SCREEN_DEFAULT_HEIGHT;
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

  eyes = sfVector3f_create(EYES_DEFAULT_X, EYES_DEFAULT_Y, EYES_DEFAULT_Z);
  dimensions = sfVector3f(SCREEN_DEFAULT_WIDTH, SCREEN_DEFAUTL_HEIGHT);
  screen->eyes = eyes;
  screen->dimensions = dimensions;
  screen->objects_count = 0;
  screen->lights_count = 0;
  error = init_framebuffer(&screen->buffer);
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
