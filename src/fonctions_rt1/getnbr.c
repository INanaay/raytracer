/*
** getnbr.c for  in /home/NANAA/projets/CPE_2016_matchstick
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Feb 13 13:35:30 2017 Nathan Lebon
** Last update Tue Mar 28 12:13:59 2017 NANAA
*/

#include "include/ray.h"

int     my_getnbr(char *str)
{
  int   i;
  int   n;
  int   nb;

  i = 0;
  n = 0;
  nb = 0;
  while (str[i] < '0' || str[i] > '9' && str[i])
    {
      if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	n = 1;
      i = i + 1;
    }
  while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
    {
      nb = nb * 10 + (str[i] - 48);
      i = i + 1;
    }
  if (n == 1)
    return (- nb);
  return (nb);
}
