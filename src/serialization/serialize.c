/*
** serialize.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/serialization
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Sat Apr 22 17:08:13 2017 flavian gontier
** Last update Thu May 25 16:21:59 2017 flavian gontier
*/

#include <fcntl.h>
#include "libmy.h"
#include "raytracer.h"

static int	serialize_objects(int fd, t_listObject *objects)
{
  int		bytes;
  int		total;
  t_nodeObject	*node;

  node = objects->begin;
  bytes = write(fd, &objects->count, sizeof(objects->count));
  total = sizeof(size_t) + (sizeof(int) + sizeof(sfVector3f) * 2 +
    sizeof(sfColor) + sizeof(float) + sizeof(bool) * 3) * objects->count;
  while (node != NULL)
  {
    bytes += write(fd, &node->object.type, sizeof(int));
    bytes += write(fd, &node->object.position, sizeof(sfVector3f) * 2);
    bytes += write(fd, &node->object.color, sizeof(sfColor));
    bytes += write(fd, &node->object.value, sizeof(float));
    bytes += write(fd, &node->object.is_damier, sizeof(bool) * 3);
    node = node->next;
  }
  if (bytes != total)
  {
    my_puterr("ERROR: Cannot write objects.\n");
    return (-1);
  }
  return (bytes);
}

static int	serialize_lights(int fd, t_light *lights, size_t count)
{
  size_t	index;
  int		bytes;
  int		total;
  t_light	*light;

  index = 0;
  total = sizeof(size_t) + sizeof(t_light) * count;
  bytes = write(fd, &count, sizeof(count));
  if (bytes != sizeof(count))
  {
    my_puterr("ERROR: Cannot serialize lights.\n");
    return (-1);
  }
  while (index < count)
  {
    light = lights + index;
    bytes += write(fd, light, sizeof(t_light));
    index += 1;
  }
  if (bytes != total)
  {
    my_puterr("ERROR: Cannot serialize light.\n");
    return (-1);
  }
  return (bytes);
}

static int	serialize_screen(int fd, t_screen *screen)
{
  int		bytes;

  bytes = 0;
  bytes = write(fd, &screen->dimensions, sizeof(screen->dimensions));
  bytes += write(fd, &screen->eyes, sizeof(screen->eyes));
  if (bytes != (sizeof(screen->dimensions) + sizeof(screen->eyes)))
  {
    my_puterr("ERROR: Cannot serialize screen.\n");
    return (-1);
  }
  return (bytes);
}

int	serialize(t_screen *screen, const char *save_path)
{
  int	fd;
  int	ret;

  if (save_path == NULL)
  {
    my_puterr("ERROR: Cannot serialize with given path");
    return (-1);
  }
  fd = open(save_path, O_CREAT | O_WRONLY, 0644);
  if (fd < 0)
  {
    my_puterr("ERROR: Cannot open the save file.\n");
    return (-1);
  }
  printf("Opened.\n");
  ret += serialize_screen(fd, screen);
  ret += serialize_objects(fd, &screen->objects);
  ret += serialize_lights(fd, screen->lights, screen->lights_count);
  printf("Serialized.\n");
  close(fd);
  return (ret);
}
