/*
** my_strlen.c for libmy in /home/flavian.gontier/C_Graphical/libmy3d/utils
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Wed Dec 21 16:53:46 2016 flavian gontier
** Last update Tue Apr 04 17:14:22 2017 flavian gontier
*/

#include <stdlib.h>

int		my_strlen(const char *str)
{
  register int	iterator;

  iterator = 0;
  if (str == NULL)
    return (0);
  while (str[iterator] != 0)
    {
      iterator = iterator + 1;
    }
  return (iterator);
}
