/*
** set_scene.c for Project-Master in /home/NANAA/Projets/raytracer1/bonus
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Tue Mar 28 11:10:31 2017 NANAA
** Last update Tue Mar 28 15:51:31 2017 NANAA
*/

#include "include/ray.h"

int	is_number(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (s[i] >= '0' && s[i] <= '9')
	i++;
      else
	return (0);
    }
  return (1);
}

char	**file_to_double(char *path)
{
  char	*temp;
  char	**file;

  temp = file_to_arr(path);
  file = my_str_to_wordtab(temp, '\n');
  return (file);
}

int	 check_line_correct(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      if (is_number(tab[i]) == 0)
	return (0);
      i++;
    }
  if (i != 5)
    return (0);
  return (1);
}

t_object	**set_scene(char **file, t_object **objs)
{
  int		len;
  int		i;
  int		j;
  char		**line;

  len = 0;
  while (file[len])
    len++;
  objs = create_objs_tab(objs, len);
  i = 0;
  while (file[i])
    {
      line = my_str_to_wordtab(file[i], ',');
      objs[i] = set_object(my_getnbr(line[0]), my_getnbr(line[1]));
      objs[i] = set_object_position(objs[i],
				    my_getnbr(line[2]), my_getnbr(line[3]),
				    my_getnbr(line[4]));
      i++;
    }
  return (objs);
}
