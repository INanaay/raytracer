/*
** init.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Tue Apr 11 11:36:42 2017 flavian gontier
** Last update Mon May 15 10:59:18 2017 NANAA
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libmy.h"
#include "raytracer.h"

int		init_framebuffer(t_framebuffer *buffer)
{
  size_t	buffer_size;

  buffer->dimensions.x = FRAMEBUFFER_DEFAULT_WIDTH;
  buffer->dimensions.y = FRAMEBUFFER_DEFAULT_HEIGHT;
  buffer_size = FRAMEBUFFER_DEFAULT_WIDTH * FRAMEBUFFER_DEFAULT_HEIGHT;
  buffer->pixels = my_calloc(sizeof(sfUint8) *
			     buffer_size * 4);
  if (buffer->pixels == NULL)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}

void		init_lights(t_light *lights)
{
  lights[0].coordinates = sfVector3f_create(-200, 0 , 10);
  lights[0].color = create_color(255, 255, 255, 255);
  lights[1].coordinates = sfVector3f_create(0, 10, 100);
  lights[1].color = create_color(255, 255, 255, 255);
  lights[2].coordinates = sfVector3f_create(100, 60, 40);
  lights[2].color = create_color(255, 255, 255, 255);
}

int		init_screen(t_screen *screen)
{
  int		error;

  screen->eyes = sfVector3f_create(EYES_DEFAULT_X, EYES_DEFAULT_Y,
				   EYES_DEFAULT_Z);
  screen->dimensions = sfVector2i_create(FRAMEBUFFER_DEFAULT_WIDTH,
					 FRAMEBUFFER_DEFAULT_HEIGHT);
  screen->lights_count = 3;
  screen->last_object = -1;
  screen->current_light = 0;
  error = init_framebuffer(&screen->framebuffer);
  screen->rotate = sfVector3f_create(0, 0, 0);
  screen->translate = sfVector3f_create(0, 0 , 0);
  if (error)
    return (EXIT_ERROR);
  if (!(screen->buttons = malloc(sizeof(t_button) * NB_BUTTONS)) ||
      !(screen->lights = malloc(sizeof (t_light) * screen->lights_count)))
    return (EXIT_ERROR);
  init_lights(screen->lights);
  error = init_buttons(screen->buttons);
  if (error)
    return (EXIT_ERROR);
  error = listObject_init(&screen->objects);
  add_object(&(screen->objects), plane);
  screen->window = my_create_window(NAME, WINDOW_DEFAULT_WIDTH,
				    WINDOW_DEFAULT_HEIGHT);
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
