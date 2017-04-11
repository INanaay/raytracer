/*
** listString_getIndex.c for lib in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_minishell2/src/lib/list/listString
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Tue Apr 04 14:01:41 2017 flavian gontier
** Last update Sun Apr 09 13:25:51 2017 flavian gontier
*/

#include "libmy.h"
#include <stdio.h>

/*
** return the index of the element if found.
** else return -1
*/
int	listString_contains(t_listString *list, const char *element)
{
  size_t	counter;
  size_t	len;

  counter = 0;
  len = my_strlen(element);
  while (counter < list->count)
  {
    if (my_strncmp(list->elements[counter], element, len) == 0)
      return (counter);
    counter += 1;
  }
  return (-1);
}
