/*
** my_put.c for libmy in /home/flavian.gontier/C_Graphical/libmy3d/utils
**
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
**
** Started on  Wed Dec 21 16:51:06 2016 flavian gontier
** Last update Tue Mar 21 18:49:56 2017 nathan
*/

#include <unistd.h>
#include "libmy.h"

void	my_put(int output, char *str)
{
  int	len;

  len = my_strlen(str);
  write(output, str, len);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_put84(char *s)
{
  my_puterr(s);
  return (EXIT_ERROR);
}
