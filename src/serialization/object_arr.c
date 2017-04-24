/*
** object_arr.c for Project-Master in /home/NANAA/Projets/raytracer2/src/serialization
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Apr 24 11:37:19 2017 NANAA
** Last update Mon Apr 24 12:28:24 2017 NANAA
*/

int	init_objects(t_object *objects, int objects_count)
{
  objects = malloc(sizeof (t_object) * (objects_count + 1));
  if (objects == NULL)
    return (EXIT_ERROR);
  return (EXIT_SUCCESS);
}

t_object	*realloc_arr(t_object *objects, int objects_count)
{
  t_ojects	*new;
  int		index;

  index = 0;
  new = malloc(sizeof (t_object) * objects_count + 1);
  if (new == NULL)
    return (EXIT_ERROR);
  while (index < objects_count)
    {
      new[index] = objects[index];
      index++;
    }
  free(objects);
  return (new);
}

int	add_oject(t_objects *objects, int objects_count)
{
  
}
