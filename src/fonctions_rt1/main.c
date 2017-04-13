/*
** main.c for  in /home/NANAA/projets/raytracer1/bonus
** 
** Made by Nathan Lebon
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Tue Feb 28 15:54:57 2017 Nathan Lebon
** Last update Tue Mar 28 15:51:18 2017 NANAA
*/

#include "include/ray.h"

t_object	**default_scene(t_object **objs)
{
  t_object	*obj;

  obj = set_object(SPHERE, 40);
  obj = set_object_position(obj, 10, 0, 50);
  objs = create_objs_tab(objs, NB_OBJ);
  objs[0] = obj;
  objs[1] = set_object(PLANE, 0);
  objs[2] = NULL;
  return (objs);
}

int		main(int ac, char **av)
{
  t_win		*win;
  t_object	**objs;
  t_eye		*eye;
  char		**file;

  if (ac == 1)
    objs = default_scene(objs);
  else if (ac == 2)
    {
      if ((file = file_to_double(av[1])) == NULL)
	return (84);
      if ((objs = set_scene(file, objs)) == NULL)
	return (84);
    }
  else
    return (84);
  eye = set_eye(eye, -200, 0, 10);
  eye = set_light(eye, -200, 0, 10);
  win = set_window();
  raytrace_scene(eye, objs, win);
  open_window(win, objs, eye);
}
