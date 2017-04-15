/*
** ray.h for Project-Master in /home/NANAA/Projets/raytracer2/include
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Apr 10 14:47:35 2017 NANAA
** Last update Sat Apr 15 12:09:13 2017 NANAA
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
# define NB_BUTTONS 4
# define IMAGE_NAME "src/button.png"
# define FRAMEBUFFER_X_POSITION 200

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

typedef struct		s_button
{
  sfVector2f		position;
  sfColor		color;
  sfSprite		*sprite;
}			t_button;

typedef struct		s_screen
{
  sfVector2i		dimensions;
  sfVector3f		eyes;
  t_framebuffer		framebuffer;
  t_object		*objects;
  int32_t		objects_count;
  t_light		*lights;
  int32_t		lights_count;
  t_button		*buttons;
  sfRenderWindow	*window;
}			t_screen;

void			*my_memset(char *ptr, int len, int value);
void			*my_calloc(size_t len);
int			init_screen(t_screen *screen);
int			load_screen(t_screen *screen, char *filepath);
int			init_framebuffer(t_framebuffer *framebuffer);
sfVector3f	        sfVector3f_create(float x, float y, float z);
sfVector2i	        sfVector2i_create(int x, int y);
sfRenderWindow          *my_create_window(char *name, int width, int height);
void			show_window(t_screen *);
int		        print_gui(t_screen *screen);
int	                set_button(t_button *buttons);
void			my_put_pixel(t_framebuffer *buffer, sfVector2i coords, sfColor color);
sfVector2f		sfVector2f_create(float, float);
int			check_buttons(t_screen *);
int	                find_nearest_intersect(t_object **objects,
					       sfVector3f dir_vector, sfVector3f eyes);
void			handle_poll_events(t_screen *screen);

#endif
