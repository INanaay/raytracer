/*
** my_putstr.c for libmy in /home/flavian.gontier/C_Graphical/libmy3d/utils
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Wed Dec 21 16:56:47 2016 flavian gontier
** Last update Tue Feb 14 15:28:37 2017 flavian gontier
*/

#include "libmy.h"

# define OUTPUT 1

void	my_putstr(char *str)
{
  int	len;

  len = my_strlen(str);
  write(1, str, len);
}
