/*
** my_strindex.c for tetris in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_tetris/src/lib/string
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Thu Mar 16 16:55:00 2017 flavian gontier
** Last update Thu Mar 16 17:06:53 2017 flavian gontier
*/

int	my_strindex(char *str, char c)
{
  register int	index;

  index = 0;
  while (str[index] != 0)
  {
    if (str[index] == c)
      return (index);
    index = index + 1;
  }
  return (-1);
}
