/*
** serialize.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/serialization
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Sat Apr 22 17:08:13 2017 flavian gontier
** Last update Mon Apr 24 15:33:37 2017 flavian gontier
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "raytracer.h"

static int	deserialize_framebuffer(int fd, t_framebuffer *buffer)
{
  size_t	index;
  size_t	count;
  int		bytes;

  bytes = read(fd, &buffer->dimensions, sizeof(buffer->dimensions));
  if (bytes != sizeof(buffer->dimensions))
    return (EXIT_ERROR);
  count = (buffer->dimensions.x * buffer.dimensions.y) * 4;
  bytes = read(fd, &buffer->pixels, count);
  if (bytes != count)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}

static int	deserialize_objects(int fd, t_objects *objects, size_t count)
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

static int	deserialize_lights(int fd, t_light *lights, size_t count)
{
  size_t	index;
  int		bytes;
  t_ligth	*ligth;

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

static int	deserialize_buttons(int fd, t_screen *screen)
{
  size_t	index;
  size_t	bytes;

  index = 0;
  read(
}

int	deserialize(t_screen *screen, const char *save_path)
{
  int	fd;
  int	ret;
  int	bytes;

  if (save_path == NULL)
    return (EXIT_ERROR);
  fd = open(save_path, O_RDONLY);
  if (fd < 0)
    return (EXIT_ERROR);
  ret |= read(fd, &screen->dimensions, sizeof(screen->dimensions));
  ret |= read(fd, &screen->eyes, sizeof(screen->eyes));
  ret |= deserialize_framebuffer(&screen->framebuffer);
  ret |= deserialize_objects(&screen);
  ret |= deserialize_lights(&screen);
  ret |= deserialize_buttons(&screen);
  return (ret);
}
