/*
** my_strcpy.c for lib in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_minishell1
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Mon Jan 16 21:49:18 2017 flavian gontier
** Last update Fri Feb 03 12:15:09 2017 flavian gontier
*/

char		*my_strcpy(char *dest, char *src)
{
  register int	index;

  index = 0;
  while (src[index] != 0)
    {
      dest[index] = src[index];
      index = index + 1;
    }
  dest[index] = 0;
  return (dest);
}
