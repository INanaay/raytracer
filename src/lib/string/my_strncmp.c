/*
** my_strncmp.c for lib in /home/flavian.gontier/Tek1/C_Prog_Elem/PSU_2016_minishell1
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.net>
** 
** Started on  Thu Jan 19 12:52:47 2017 flavian gontier
** Last update Wed Apr 05 23:25:32 2017 flavian gontier
*/

int		my_strncmp(char *s1, char *s2, int n)
{
  register int	index;

  index = 0;
  while (index < n)
    {
      if (s1[index] == 0 || s2[index] == 0)
	return (s1[index] - s2[index]);
      if (s1[index] != s2[index])
	return (s1[index] - s2[index]);
      index = index + 1;
    }
  return (0);
}
