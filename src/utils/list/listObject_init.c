/*
** listObject_init.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/utils
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Mon Apr 24 16:29:28 2017 flavian gontier
** Last update Thu Apr 27 14:15:52 2017 NANAA
*/

#include "libmy.h"
#include "raytracer.h"

int	listObject_init(t_listObject *list)
{
  list->count = 0;
  list->begin = NULL;
  list->end = NULL;
  return (EXIT_SUCCESS);
}
