/*
** serialize.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/serialization
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Sat Apr 22 17:08:13 2017 flavian gontier
** Last update Thu May 25 15:25:01 2017 flavian gontier
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "raytracer.h"
#include "libmy.h"

static int	deserialize_framebuffer(int fd, t_framebuffer *buffer)
{
  int		bytes;
  int		frame_size;
  int		total_size;

  bytes = read(fd, &buffer->dimensions, sizeof(buffer->dimensions));
  if (bytes != sizeof(buffer->dimensions))
  {
    my_puterr("ERROR: Cannot deserialize framebuffer (1).\n");
    return (-1);
  }
  frame_size = (buffer->dimensions.x * buffer->dimensions.y * 4);
  total_size = frame_size + sizeof(buffer->dimensions);
  bytes = read(fd, &buffer->dimensions, sizeof(buffer->dimensions));
  bytes += read(fd, &buffer->pixels, frame_size);
  if (bytes != total_size)
  {
    my_puterr("ERROR: Cannot deserialize framebuffer (2).\n");
    return (-1);
  }
  return (bytes);
}

static int	deserialize_objects(int fd, t_listObject *objects)
{
  int		bytes;
  int		total;
  t_object	object;

  bytes = read(fd, &objects->count, sizeof(objects->count));
  total = sizeof(size_t) + (sizeof(int) + sizeof(sfVector3f) * 2 +
    sizeof(sfColor) + sizeof(float) + sizeof(bool) * 3) * objects->count;
  while (objects->count > 0)
  {
    bytes += read(fd, &object.type, sizeof(int));
    bytes += read(fd, &object.position, sizeof(sfVector3f) * 2);
    bytes += read(fd, &object.color, sizeof(sfColor));
    bytes += read(fd, &object.value, sizeof(float));
    bytes += read(fd, &object.is_damier, sizeof(bool) * 3);
    set_object(&object, object.type);
    listObject_add(objects, object);
  }
  if (bytes != total)
  {
    my_puterr("ERROR: Cannot write objects.\n");
    return (-1);
  }
  return (bytes);
}

static int	deserialize_lights(int fd, t_screen *screen)
{
  size_t	index;
  int		bytes;
  int		total;

  index = 0;
  bytes = read(fd, &screen->lights_count, sizeof(screen->lights_count));
  total = screen->lights_count * sizeof(t_light) + sizeof(size_t);
  screen->lights = malloc(sizeof(t_light) * screen->lights_count);
  if (bytes != sizeof(screen->lights_count))
  {
    my_puterr("ERROR: Cannot deserialize lights.\n");
    return (-1);
  }
  while (index < screen->lights_count)
  {
    bytes += read(fd, screen->lights + index, sizeof(t_light));
    index += 1;
  }
  if (bytes != total)
  {
    my_puterr("ERROR: Cannot serialize light.\n");
    return (-1);
  }
  return (bytes);
}

static int	deserialize_screen(int fd, t_screen *screen)
{
  int		bytes;

  bytes = 0;
  bytes = read(fd, &screen->dimensions, sizeof(screen->dimensions));
  bytes += read(fd, &screen->eyes, sizeof(screen->eyes));
  if (bytes != (sizeof(screen->dimensions) + sizeof(screen->eyes)))
  {
    my_puterr("ERROR: Cannot serialize screen.\n");
    return (-1);
  }
  return (bytes);
}

int	deserialize(t_screen *screen, const char *save_path)
{
  int	fd;
  int	ret;

  if (save_path == NULL)
    return (-1);
  fd = open(save_path, O_CREAT);
  if (fd < 0)
    return (-1);
  ret += deserialize_screen(fd, screen);
  ret += deserialize_framebuffer(fd, &screen->framebuffer);
  ret += deserialize_objects(fd, &screen->objects);
  ret += deserialize_lights(fd, screen);
  return (ret);
}
