/*
** get_decimal.c for  in /home/anatole.zeyen/CPE_2016_corewar/src/vm/lib/string
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Mon Mar 27 12:36:43 2017 anatole zeyen
** Last update Mon Mar 27 14:09:52 2017 flavian gontier
*/

#include <unistd.h>
#include <math.h>

#include "libmy.h"

int32_t		my_get_decimal(char *hexa)
{
  int32_t	result;
  int		index;
  int		suffix_len;
  int		base_len;

  index = 0;
  suffix_len = my_strlen(HEXA_SUFFIX);
  if (my_strncmp(hexa, HEXA_SUFFIX, suffix_len) == 0)
    index = 2;
  base_len = my_strlen(HEXA_BASE);
  result = 0;
  while (hexa[index] != 0)
  {
    result *= base_len;
    result += my_strindex(HEXA_BASE, hexa[index]);
    index = index + 1;
  }
  return (result);
}

char	*my_get_hexadecimal(int32_t nb)
{
  char	hexadecimal[16];
  char	*result;
  int	index;
  int	base_len;
  int	suffix_len;

  base_len = my_strlen(HEXA_BASE);
  index = base_len - 1;
  hexadecimal[index] = 0;
  index = index - 1;
  while (nb >= 0)
  {
    hexadecimal[index] = HEXA_BASE[nb % base_len];
    nb /= base_len;
    if (nb > 0)
      index = index - 1;
    nb = (nb == 0) ? -1 : nb;
  }
  suffix_len = my_strlen(HEXA_SUFFIX);
  result = malloc(sizeof(char) * (suffix_len + index + 1));
  my_strcpy(result, HEXA_SUFFIX);
  my_strcat(result, &hexadecimal[index]);
  return (result);
}
