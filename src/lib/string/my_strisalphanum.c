/*
** my_strisalphanum.c for shell in /home/flavian.gontier/Tek1/C_Prog_Elem/minishell/src
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Sun Jan 22 00:07:27 2017 flavian gontier
** Last update Sun Jan 22 00:15:28 2017 flavian gontier
*/

#include "libmy.h"

int		my_strisalphanum(char *str)
{
  register int	index;

  index = 0;
  while (str[index] != 0)
    {
      if (my_isalphanum(str[index]) == 0)
	return (0);
      index = index + 1;
    }
  return (1);
}
