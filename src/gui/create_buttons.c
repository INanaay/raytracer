/*
** create_buttons.c for Project-Master in /home/NANAA/Projets/raytracer2/src/gui
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Wed May 10 11:36:56 2017 NANAA
** Last update Sat May 27 11:29:50 2017 NANAA
*/

#include "raytracer.h"

sfText		*create_text()
{
  sfFont	*font;
  sfText	*button_text;

  font = sfFont_createFromFile("arial.ttf");
  if (font == NULL)
    return (NULL);
  button_text = sfText_create();
  sfText_setFont(button_text, font);
  sfText_setCharacterSize(button_text, 20);
  sfText_setColor(button_text, sfBlack);
  return (button_text);
}

int		init_buttons(t_button *buttons)
{
  sfTexture	*texture;
  sfSprite	*sprite;

  sprite = sfSprite_create();
  if ((texture = sfTexture_createFromFile(IMAGE_NAME, NULL)) == NULL)
    return (EXIT_ERROR);
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfSprite_setScale(sprite, sfVector2f_create(0.5, 0.5));
  set_buttons(&(*buttons), sprite);
  return (EXIT_SUCCESS);
}

static void	set_buttons_text(t_button *buttons)
{
  buttons[0].text = "sphere";
  buttons[1].text = "cone";
  buttons[2].text = "cylinder";
  buttons[3].text = "R -";
  buttons[4].text = "R +";
  buttons[5].text = "damier";
  buttons[6].text = "G -";
  buttons[7].text = "G +";
  buttons[8].text = "Temp";
  buttons[9].text = "B -";
  buttons[10].text = "B +";
  buttons[11].text = "Temp";
  buttons[12].text = "aliasing -";
  buttons[13].text = "aliasing +";
  buttons[14].text = "size +";
  buttons[15].text = "delete";
  buttons[16].text = "save";
  buttons[17].text = "size -";
}

void		set_buttons(t_button *buttons, sfSprite *sprite)
{
  int		id;
  int		i;
  sfVector2f	position;

  position = sfVector2f_create(1150, 10);
  id = 0;
  i = 0;
  while (i < NB_BUTTONS)
    {
      buttons[i].id = id++;
      buttons[i].sprite = sprite;
      buttons[i].position = position;
      position.x += 180;
      if (position.x > 150 * 3 + 1150)
	{
	  position.x = 1150;
	  position.y += 75;
	}
      i++;
    }
  set_buttons_text(buttons);
}
