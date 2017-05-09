/*
** translate.c for Project-Master in /home/NANAA/Projets/raytracer1/src
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Mar 13 11:20:50 2017 NANAA
** Last update Tue May  9 13:44:31 2017 NANAA
*/

#include "raytracer.h"

sfVector3f translate(sfVector3f to_translate, sfVector3f translations)
{
  to_translate.x += translations.x;
  to_translate.y += translations.y;
  to_translate.z += translations.z;
  return (to_translate);
}
