/*
** listObject_add.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/utils
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Mon Apr 24 16:31:24 2017 flavian gontier
** Last update Mon Apr 24 18:38:41 2017 flavian gontier
*/

int		listObject_add(t_listObject *list, t_object object)
{
  t_node	*node;

  node = malloc(sizeof(t_nodeObject));
  if (node == NULL)
    return (EXIT_ERROR);
  node->object = object;
  node->next = NULL;
  if (list->count == 0)
  {
    list->begin = node;
    list->end = node;
    node->prev = NULL;
  }
  else
  {
    node->prev = list->end;
    list->end = node;
  }
  list->length += 1;
  return (EXIT_SUCCESS);
}
