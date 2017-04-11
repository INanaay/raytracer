/*
** my_strtab.c for libmy in /home/flavian.gontier/C_Graphical/libmy3d
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Wed Dec 21 20:20:02 2016 flavian gontier
** Last update Sat Jan 21 00:24:29 2017 flavian gontier
*/

#include <unistd.h>
#include "libmy.h"

char		**my_strtab(char *str)
{
  register int	index;
  register int	line;
  char		**tab;
  int		line_count;

  line_count = my_strcontains(str, '\n');
  tab = my_calloc(sizeof(char **) * (line_count + 1));
  if (tab == NULL)
    return (NULL);
  index = 0;
  line = 0;
  while (str[index] != 0)
    {
      tab[line] = my_linedup(&str[index]);
      if (tab[line] == NULL)
	return (NULL);
      while (str[index] != '\n')
	index = index + 1;
      index = index + 1;
      line = line + 1;
    }
  return (tab);
}
