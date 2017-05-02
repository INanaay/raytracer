/*
** my_memset.c for libmy in /home/flavian.gontier/C_Graphical/lib
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Thu Dec 22 00:26:31 2016 flavian gontier
** Last update Tue May  2 15:52:13 2017 NANAA
*/

void		*my_memset(char *ptr, int len, int value)
{
  register int	index;

  index = 0;
  while (index < len)
    {
      ptr[index] = value;
      index = index + 1;
    }
  return (ptr);
}
