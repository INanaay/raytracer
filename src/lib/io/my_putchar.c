/*
** my_putchar.c for navy in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_navy/src/lib/io
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Tue Feb 07 21:00:03 2017 flavian gontier
** Last update Tue Feb 07 21:15:22 2017 flavian gontier
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
