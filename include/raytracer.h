/*
** ray.h for Project-Master in /home/NANAA/Projets/raytracer2/include
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Apr 10 14:47:35 2017 NANAA
** Last update Mon Apr 10 19:12:50 2017 NANAA
*/

#ifndef RAY_H_
# define RAY_H_

# include <SFML/Graphics.h>
# include <SFML/Window.h>
# include <stdbool.h>

# define NAME "raytracer2"
# define FRAMEBUFFER_DEFAULT_WIDTH 640
# define FRAMEBUFFER_DEFAULT_HEIGHT 480
# define WINDOW_DEFAULT_WIDTH 800
# define WINDOW_DEFAULT_HEIGHT 480
# define BYTES_PER_PIXEL 4
# define BITS_PER_PIXEL 32

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			pixel_count;
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

typedef struct		s_configuration
{
  sfVector2i		framebuffer_dimensions;
  sfVector2i		window_dimensions;
  sfVector3f		light_position[4];
  sfVector3f		eyes_position;
}			t_configuration;

typedef struct		s_button
{
  sfVector2i		dimensions;
  char			text[32];
}			t_button;

sfRenderWindow          *my_create_window(char *name, int width, int height);
sfUint8                 *my_create_framebuffer_pixels(int pixel_count);
t_my_framebuffer        my_create_framebuffer(int width, int height);
void	                my_show_window(sfRenderWindow *win, t_my_framebuffer *fuffer);

#endif
