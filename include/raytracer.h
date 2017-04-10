/*
** ray.h for Project-Master in /home/NANAA/Projets/raytracer2/include
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Apr 10 14:47:35 2017 NANAA
** Last update Mon Apr 10 17:11:53 2017 flavian gontier
*/

#ifndef RAY_H_
# define RAY_H_

# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Color.h>
# include <SFML/Window/Event.h>
# include <SFML/Graphics/Texture.h>
# include <stdbool.h>

# define FRAMEBUFFER_DEFAULT_WIDTH 640
# define FRAMEBUFFER_DEFAULT_HEIGHT 480
# define WINDOW_DEFAULT_WIDTH 800
# define WINDOW_DEFAULT_HEIGHT 480

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  sfVector2i		dimensions;
}			t_my_framebuffer;

typedef t_my_framebuffer framebuffer;

typedef struct		s_object
{
  sfVector3f		position;
  sfColor		color;
  float			value;
  float			(*intersect)(sfVector3f, sfVector3f, float);
  bool			is_transparent;
  bool			is_mirror;
}			t_oject;

typedef struct		s_screen
{
  sfRenderWindow	*window;
  t_my_framebuffer	buffer;
  sfVector2i		dimensions;
}			t_screen;

typedef struct		s_configuration;
{
  sfVector2i		framebuffer_dimensions;
  sfVector2i		window_dimensions;
  sfVector3f		light_position[4];
  sfVector3f		eyes_position;
}			t_configuration;

#endif
