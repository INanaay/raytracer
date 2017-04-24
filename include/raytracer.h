/*
** ray.h for Project-Master in /home/NANAA/Projets/raytracer2/include
** 
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
** 
** Started on  Mon Apr 10 14:47:35 2017 NANAA
** Last update Mon Apr 24 16:30:58 2017 flavian gontier
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
# define WINDOW_DEFAULT_WIDTH 1000
# define WINDOW_DEFAULT_HEIGHT 480
# define BYTES_PER_PIXEL 4
# define BITS_PER_PIXEL 32
# define EXIT_ERROR 1
# define EXIT_SUCCESS 0
# define SCREEN_DEFAULT_WIDTH 1000
# define SCREEN_DEFAULT_HEIGHT 480
# define EYES_DEFAULT_X - 200
# define EYES_DEFAULT_Y 0
# define EYES_DEFAULT_Z 0
# define NB_BUTTONS 4
# define IMAGE_NAME "src/button.png"
# define SCENE_DEFAULT_X 350
# define SCENE_DEFAULT_Y 0

/*
** Graphic types
*/

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  sfVector2i		dimensions;
}			t_my_framebuffer;

typedef t_my_framebuffer t_framebuffer;

typedef struct		s_object
{
  int			id;
  sfVector3f		position;
  sfColor		color;
  float			value;
  bool			is_transparent;
  bool			is_mirror;
  float			(*intersect)(sfVector3f, sfVector3f, float);
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
  t_listObject		objects;
  t_light		*lights;
  size_t		lights_count;
  t_button		*buttons;
  size_t		buttons_count;
  sfRenderWindow	*window;
}			t_screen;

/*
** utils
*/

typedef struct		s_nodeObject
{
  struct s_object	object;
  struct s_nodeObject	*next;
  struct s_nodeObject	*prev;
}			t_nodeObject;

typedef struct		s_listObject
{
  size_t		count;
  t_nodeObject		*begin;
  t_nodeObject		*end;
}			t_listObject;

/*
** Prototypes
*/

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
int	                find_nearest_intersect(t_object *objects,
					       sfVector3f dir_vector, sfVector3f eyes, int nb_objects);
void			handle_poll_events(t_screen *screen);
void            draw_objects(t_my_framebuffer *buffer, t_object *objects, sfVector3f eyes, int nb_objects);

#endif
