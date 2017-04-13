/*
** file_to_double.c for Project-Master in /home/NANAA/Projets/Corewar/asm
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Tue Mar 14 12:44:56 2017 NANAA
** Last update Tue Mar 28 11:31:38 2017 NANAA
*/

#include <unistd.h>
#include <fcntl.h>
#include "include/ray.h"

#define READ_SIZE 4

char	*file_to_arr(const char *path)
{
  int	fd;
  char	buff[READ_SIZE + 1];
  char	*str;
  int	size;

  str = NULL;
  if ((fd = open(path, O_RDONLY)) == -1)
    return (NULL);
  while ((size = read(fd, buff, READ_SIZE)) > 0)
    {
      buff[size] = 0;
      str = my_realloc(str, my_strlen(str) + my_strlen(buff));
      str = my_strcat(str, buff);
    }
  return (str);
}

