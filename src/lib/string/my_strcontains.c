/*
** my_strcontains.c for lib in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_minishell1
**
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
**
** Started on  Mon Jan 16 19:47:37 2017 flavian gontier
** Last update Mon Mar 20 16:40:13 2017 nathan
*/

int	my_strcontains(char *str, char c)
{
  register int	index;
  int		result;

  index = 0;
  result = 0;
  while (str[index] != 0)
    {
      if (str[index] == c)
	result = result + 1;
      index = index + 1;
    }
  return (result);
}
