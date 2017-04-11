/*
** my_atoi.c for libmy in /home/flavian.gontier/C_Graphical/libmy3d/utils
**
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
**
** Started on  Wed Dec 21 16:18:55 2016 flavian gontier
** Last update Fri Mar 17 17:09:45 2017 nathan
*/

#include <stdlib.h>

# define is_digit(x) (x >= '0' && x <= '9')

int	my_atoi(char *str)
{
  int	result;
  char	sign;

  result = 0;
  sign = 1;
  if (str == NULL)
    return (0);
  if (*str == '-' || *str == '+')
    {
      sign = (*str == '-') ? -1 : 1;
      str++;
    }
  while (*str != 0)
    {
      if (is_digit(*str))
	{
	  result = result * 10;
	  result = result + (*str - '0');
	}
      else
	return (result);
      str++;
    }
  return (result * sign);
}

int	get_nbrlen(int nbr)
{
  int	nbr_len;
  int	tmp;

  nbr_len = 0;
  tmp = nbr;
  while (tmp > 9)
    {
      tmp = tmp / 10;
      nbr_len++;
    }
  nbr_len++;
  return (nbr_len);
}

char	*my_revatoi(int nbr)
{
  int	nbr_len;
  char	*res;

  nbr_len = get_nbrlen(nbr) - 1;
  nbr_len = (nbr < 0) ? nbr_len + 1 : nbr_len;
  res = malloc(sizeof(char) * (nbr_len + 2));
  res[nbr_len + 1] = 0;
  res[0] = (nbr < 0) ? '-' : res[0];
  while (nbr > 9)
    {
      res[nbr_len--] = (nbr % 10) + 48;
      nbr = nbr / 10;
    }
  res[nbr_len--] = nbr + 48;
  return (res);
}
