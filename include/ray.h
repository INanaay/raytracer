/*
** ray.h for Project-Master in /home/NANAA/Projets/raytracer2/include
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Apr 10 14:47:35 2017 NANAA
** Last update Mon Apr 10 16:30:29 2017 NANAA
*/

#ifndef RAY_H_
# define RAY_H_

# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Color.h>
# include <SFML/Window/Event.h>
# include <SFML/Graphics/Sprite.h>
# include <SFML/Graphics/Texture.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define FRAME_W 640
# define FRAME_H 480
# define WINDOW_W 800
# define WINDOW_H 480

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			pixels_count;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef t_my_framebuffer framebuffer;

typedef struct		s_object
{
  sfVector3f		pos;
  float			value;
  sfColor		color;
  float			(*intersect)(sfVector3f, sfVector3f, float);
}			t_oject;

typedef struct		t_win
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  t_my_framebuffer	*buffer;
}			t_win;

typedef struct		s_conf
{
  sfVector3f		eye_pos;
  sfVector3f		dir_vector;
  sfVector2i		frame_pos;
  sfVector3f		*light_pos;
}

#endif
