/*
** get_next_line.c for gnl in /home/flavian.gontier/Tek1/C_Prog_Elem/CPE_2017_getnextline
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Sun Jan  8 18:15:44 2017 flavian gontier
** Last update Fri Mar 17 03:14:14 2017 flavian gontier
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libmy.h"

# define MAX_MEM 8192

char		*get_line(char *buffer)
{
  char		*result;
  register int	index;

  index = 0;
  while (buffer[index] != '\n' && buffer[index] != 0)
    index = index + 1;
  result = my_calloc(sizeof(char) * index + 1);
  my_strncpy(result, buffer, index);
  if (buffer[index] != 0)
    my_strcpy(buffer, &buffer[index + 1]);
  else
    buffer[0] = 0;
  return (result);
}

void		fd_handler(int *fd_old, int fd_new, char *buffer)
{
  if (*fd_old != fd_new)
  {
    *buffer = 0;
    *fd_old = fd_new;
  }
}

char		*get_result(char *buffer, char *result, int bytes)
{
  if (*buffer == 0 && *result == 0 && bytes == 0)
    return (NULL);
  return (result);
}

char		*get_next_line(const int file_descriptor)
{
  static char	*buffer;
  static int	fd;
  char		*result;
  char		temp[READ_SIZE + 1];
  int		bytes;

  if (buffer == NULL)
    buffer = my_calloc(sizeof(char) * MAX_MEM + 1);
  if (buffer == NULL)
    return (NULL);
  fd_handler(&fd, file_descriptor, buffer);
  bytes = 1;
  while (my_strcontains(buffer, '\n') == 0)
    {
      bytes = read(fd, temp, READ_SIZE);
      if (bytes < 0)
	return (NULL);
      temp[bytes] = 0;
      if (bytes == 0)
	break ;
      my_strcat(buffer, temp);
    }
  result = get_line(buffer);
  return (get_result(buffer, result, bytes));
}
