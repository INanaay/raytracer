/*
** my_len.c for lib in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_tetris/src/lib/string
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 15 11:57:24 2017 flavian gontier
** Last update Wed Mar 15 12:03:17 2017 flavian gontier
*/

#include <unistd.h>

size_t	my_len(char *str, char c)
{
  register size_t	length;

  length = 0;
  while (str[length] != c && str[length] != 0)
  {
    length = length + 1;
  }
  return (length);
}
