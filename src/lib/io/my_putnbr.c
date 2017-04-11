/*
** my_putnbr.c for navy in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_navy/src/lib/io
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Sun Feb 05 17:39:50 2017 flavian gontier
** Last update Tue Feb 07 21:19:44 2017 flavian gontier
*/

#include <unistd.h>

void	my_putnbr(int nb)
{
  char	tmp;

  if (nb > 9)
  {
    my_putnbr(nb / 10);
    my_putnbr(nb % 10);
  }
  else
  {
    tmp = nb + '0';
    write(1, &tmp, 1);
  }
}
