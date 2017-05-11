/*
** create_buttons.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Wed May 10 11:36:56 2017 NANAA
** Last update Thu May 11 14:15:30 2017 NANAA
*/

#include "raytracer.h"

int		init_buttons(t_button *buttons)
{
  sfTexture	*texture;
  sfSprite	*sprite;

  sprite = sfSprite_create();
  if ((texture = sfTexture_createFromFile(IMAGE_NAME, NULL)) == NULL)
    return (EXIT_ERROR);
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfSprite_setScale(sprite, sfVector2f_create(0.2, 0.2));
  set_buttons(&(*buttons), sprite);
  return (EXIT_SUCCESS);
}

void		set_buttons(t_button *buttons, sfSprite *sprite)
{
  int		id;
  int		i;
  sfVector2f	position;

  position = sfVector2f_create(700, 0);
  id = 0;
  i = 0;
  while (i < NB_BUTTONS)
    {
      buttons[i].id = id++;
      buttons[i].sprite = sprite;
      buttons[i].position = position;
      position.x += 180;
      if (position.x > 160 * 3 + 700)
	{
	  position.x = 700;
	  position.y += 75;
	}
      i++;
    }
}
