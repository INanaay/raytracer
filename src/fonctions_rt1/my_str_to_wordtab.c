/*
** my_str_to_wordtab.c for  in /home/NANAA/projets/PSU_2016_my_exec
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Jan  9 15:28:44 2017 Nathan Lebon
** Last update Tue Mar 28 10:43:17 2017 NANAA
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/ray.h"

static int	my_tab_size(const char *str, const char separator)
{
  int		i;
  int		nb_count;

  nb_count = 0;
  i = 0;
  while (str[i] == separator && str[i] && str[i] == '\n')
    i = i + 1;
  while (str[i] != 0)
    {
      if (str[i] == separator || str[i] == '\n')
	{
	  nb_count = nb_count + 1;
	  while (str[i] == separator || str[i] == '\n')
	    i = i + 1;
	}
      i = i + 1;
    }
  return (nb_count);
}

static char	**my_alloc_tab(char *str, const char c)
{
  char		**tab;
  int		i;
  int		j;
  int		len;

  len = my_tab_size(str, c) + 1;
  if ((tab = malloc(sizeof (char *) * (len + 1))) == NULL)
    return (NULL);
  (1 == 1) ? (i = 0, j = 0) : (i = 0, j = 0);
  while (str[i] == c)
    i = i + 1;
  tab[j] = &str[i];
  while (str[i])
    {
      if (str[i] == c || str[i] == '\n')
	{
	  j = j + 1;
	  while (str[i] == c || str[i] == '\n' && str[i])
	    i = i + 1;
	  tab[j] = &str[i];
	}
      i = i + 1;
    }
  tab[len] = 0;
  return (tab);
}

static char	**correct_tab(char **tab, const char c)
{
  int		i;
  int		j;

  i = 0;

  while (tab[i])
    {
      j = 0;
      while (tab[i][j] != c && tab[i][j] && tab[i][j] != '\n')
	j = j + 1;
      tab[i][j] = 0;
      i = i + 1;
    }
  return (tab);
}

char	**my_str_to_wordtab(char *str, const char c)
{
  char	**new;

  new = correct_tab(my_alloc_tab(str, c), c);
  return (new);
}
