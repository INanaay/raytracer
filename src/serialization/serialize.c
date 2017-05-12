/*
** serialize.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/serialization
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Sat Apr 22 17:08:13 2017 flavian gontier
** Last update Fri May 12 10:34:13 2017 NANAA
*/

#include "raytracer.h"

static int	serialize_framebuffer(int fd, t_framebuffer *buffer)
{
  size_t	count;
  int		bytes;

  count = (buffer->dimensions.x * buffer->dimensions.y) * 4;
  bytes = (size_t)write(fd, &buffer->dimensions, sizeof(buffer->dimensions));
  if (bytes != sizeof(buffer->dimensions))
    return (EXIT_ERROR);
  bytes = write(fd, &buffer->pixels, count);
  if (bytes != count)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}

static int	serialize_objects(int fd, t_object *objects, size_t count)
{
  size_t	index;
  size_t	length;
  int		bytes;
  t_object	*object;

  index = 0;
  bytes = write(fd, &count, sizeof(count));
  if (bytes != sizeof(count))
    return (EXIT_ERROR);
  while (index < count)
  {
    length = sizeof(t_object) - sizeof(object->intersect);
    bytes = write(fd, &object->id, sizeof(int));
    if (bytes != length)
      return (EXIT_ERROR);
    index += 1;
  }
  return (EXIT_SUCCESS);
}

static int	serialize_lights(int fd, t_light *lights, size_t count)
{
  size_t	index;
  int		bytes;
  t_light	*ligth;

  index = 0;
  bytes = write(fd, &count, sizeof(count));
  if (bytes != sizeof(count))
    return (EXIT_ERROR);
  while (index < count)
  {
    ligth = &lights[index];
    bytes = write(fd, ligth, sizeof(t_light));
    if (bytes != sizeof(t_light))
      return (EXIT_ERROR);
    index += 1;
  }
  return (EXIT_SUCCESS);
}

static int	serialize_buttons(int fd, t_button *buttons, size_t count)
{
  size_t	index;
  int		bytes;
  t_button	*button;

  index = 0;
  bytes = write(fd, &count, sizeof(size_t));
  if (bytes != sizeof(size_t))
    return (EXIT_ERROR);
  while (index < count)
  {
    button = &buttons[index];
    bytes = write(fd, button.position, sizeof(sfVector2f));
    if (bytes != sizeof(sfVector2f))
      return (EXIT_ERROR);
    bytes = write(fd, button.color, sizeof(sfColor));
    if (bytes != sizeof(sfColor))
      return (EXIT_ERROR);
    index += 1;
  }
  return (EXIT_SUCCESS);
}

int	serialize(t_screen *screen, const char *save_path)
{
  int	fd;
  int	ret;
  int	bytes;

  if (save_path == NULL)
    return (EXIT_ERROR);
  fd = open(save_path, O_CREAT);
  if (fd < 0)
    return (EXIT_ERROR);
  ret |= write(fd, &screen->dimensions, sizeof(screen->dimensions));
  ret |= write(fd, &screen->eyes, sizeof(screen->eyes));
  ret |= serialize_framebuffer(fd, &screen->framebuffer);
  ret |= serialize_objects(fd, &screen->objects, screen->objects_count);
  ret |= serialize_lights(fd, &screen->lights, screen->lights_count);
  ret |= serialize_buttons(fd, &screen->buttons, screen->buttons_count);
  return (ret);
}
