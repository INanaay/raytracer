/*
** utils.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/serialization
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Wed May 24 17:18:13 2017 flavian gontier
*/

#include <unistd.h>

int	read_bytes(int fd, int8_t *dest, size_t n)
{
  int	bytes;

  bytes = read(fd, dest, n);
  if (bytes != n)
  {
    my_puterr("ERROR: Cannot read bytes.\n");
    return (-1);
  }
  return (bytes);
}
