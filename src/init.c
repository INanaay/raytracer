/*
** init.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Tue Apr 11 11:36:42 2017 flavian gontier
** Last update Tue Apr 18 14:23:05 2017 NANAA
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "raytracer.h"

int		init_framebuffer(t_framebuffer *buffer)
{
  size_t	buffer_size;

  buffer->dimensions.x = SCREEN_DEFAULT_WIDTH;
  buffer->dimensions.y = SCREEN_DEFAULT_HEIGHT;
  buffer_size = SCREEN_DEFAULT_WIDTH * SCREEN_DEFAULT_HEIGHT;
  buffer->pixels = my_calloc(sizeof(sfUint8) *
			     buffer_size * 4);
  if (buffer->pixels == NULL)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}


int		set_button(t_button *buttons)
{
  sfTexture	*texture;
  sfSprite	*sprite;
  sfVector2f	position;
  int		i;

  position = sfVector2f_create(10, 10);
  sprite = sfSprite_create();
  texture = sfTexture_createFromFile(IMAGE_NAME, NULL);
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfSprite_setScale(sprite, sfVector2f_create(0.2, 0.2));
  if (texture == NULL)
    return (EXIT_ERROR);
  i = 0;
  while (i < NB_BUTTONS)
    {
      buttons[i].sprite = sprite;
      buttons[i].position = position;
      position.x += 180;
      if (position.x > 160 * 2 + 10)
	position = sfVector2f_create(10, position.y + 75);
      i++;
    }
  return (EXIT_SUCCESS);
}

int		init_screen(t_screen *screen)
{
  int		error;
  sfVector3f	eyes;
  sfVector2i	dimensions;

  eyes = sfVector3f_create(EYES_DEFAULT_X, EYES_DEFAULT_Y, EYES_DEFAULT_Z);
  dimensions = sfVector2i_create(SCREEN_DEFAULT_WIDTH, SCREEN_DEFAULT_HEIGHT);
  screen->eyes = eyes;
  screen->dimensions = dimensions;
  screen->objects_count = 1;
  screen->lights_count = 0;
  error = init_framebuffer(&screen->framebuffer);
  if (error)
    return (EXIT_ERROR);
  screen->buttons = malloc(sizeof(t_button) * NB_BUTTONS);
  if (screen->buttons == NULL)
    return (EXIT_ERROR);
  error = set_button(screen->buttons);
  if (error)
    return (EXIT_SUCCESS);
  screen->window = my_create_window(NAME, WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT);
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
