/*
** ray.h for Project-Master in /home/NANAA/Projets/raytracer2/include
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Apr 10 14:47:35 2017 NANAA
** Last update Tue Apr 11 15:43:18 2017 NANAA
*/

#ifndef RAY_H_
# define RAY_H_

# include <SFML/Graphics.h>
# include <SFML/Window.h>
# include <stdbool.h>
# include <stdlib.h>

# define NAME "raytracer2"
# define FRAMEBUFFER_DEFAULT_WIDTH 640
# define FRAMEBUFFER_DEFAULT_HEIGHT 480
# define WINDOW_DEFAULT_WIDTH 800
# define WINDOW_DEFAULT_HEIGHT 480
# define BYTES_PER_PIXEL 4
# define BITS_PER_PIXEL 32
# define EXIT_ERROR 1
# define EXIT_SUCCESS 0
# define SCREEN_DEFAULT_WIDTH 640
# define SCREEN_DEFAULT_HEIGHT 480
# define EYES_DEFAULT_X - 200
# define EYES_DEFAULT_Y 0
# define EYES_DEFAULT_Z 0

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  sfVector2i		dimensions;
}			t_my_framebuffer;

typedef t_my_framebuffer t_framebuffer;

typedef struct		s_object
{
  sfVector3f		position;
  sfColor		color;
  float			value;
  float			(*intersect)(sfVector3f, sfVector3f, float);
  bool			is_transparent;
  bool			is_mirror;
}			t_object;

typedef struct		s_light
{
  sfVector3f		coordinates;
  sfColor		color;
}			t_light;

typedef struct		s_screen
{
  sfVector2i		dimensions;
  sfVector3f		eyes;
  t_framebuffer		framebuffer;
  t_object		*objects;
  int32_t		objects_count;
  t_light		*lights;
  int32_t		lights_count;
}			t_screen;

typedef struct		s_button
{
  sfVector2i		coordonates;
  sfColor		color;
  char			text[32];
}			t_button;

int			init_screen(t_screen *screen);
int			load_screen(t_screen *screen, char *filepath);
int			init_framebuffer(t_framebuffer *framebuffer);
sfVector3f	        sfVector3f_create(float x, float y, float z);
sfVector2i	        sfVector2i_create(int x, int y);

#endif
