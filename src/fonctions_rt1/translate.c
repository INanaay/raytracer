/*
** translate.c for Project-Master in /home/NANAA/Projets/raytracer1/src
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Mar 13 11:20:50 2017 NANAA
** Last update Mon Mar 13 12:02:13 2017 NANAA
*/

#include "include/ray.h"

sfVector3f translate(sfVector3f to_translate, sfVector3f translations)
{
  to_translate.x += translations.x;
  to_translate.y += translations.y;
  to_translate.z += translations.z;
  return (to_translate);
}
