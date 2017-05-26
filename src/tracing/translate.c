/*
** translate.c for Project-Master in /home/NANAA/Projets/raytracer1/src
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Mon Mar 13 11:20:50 2017 NANAA
** Last update Fri May 26 17:49:46 2017 schwarzy
*/

#include "raytracer.h"

sfVector3f translate(sfVector3f to_translate, sfVector3f translations)
{
  to_translate.x += translations.x;
  to_translate.y += translations.y;
  to_translate.z += translations.z;
  return (to_translate);
}

sfVector3f inv_trans(sfVector3f to_trans, sfVector3f trans)
{
  trans.x = -trans.x;
  trans.y = -trans.y;
  trans.z = -trans.z;
  return (translate(to_trans, trans));
}
