/*
** ray.h for Project-Master in /home/NANAA/Projets/raytracer2/include
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Mon Apr 10 14:47:35 2017 NANAA
** Last update Mon May 22 17:26:25 2017 schwarzy
*/

#ifndef RAY_H_
# define RAY_H_

# include <SFML/Graphics.h>
# include <SFML/Window.h>
# include <stdbool.h>
# include <stdlib.h>

# define NBR_COLORS screen->lights_count
# define NAME "raytracer2"
# define FRAMEBUFFER_DEFAULT_WIDTH 640
# define FRAMEBUFFER_DEFAULT_HEIGHT 480
# define WINDOW_DEFAULT_WIDTH 1250
# define WINDOW_DEFAULT_HEIGHT 480
# define BYTES_PER_PIXEL 4
# define BITS_PER_PIXEL 32
# define EXIT_ERROR 1
# define EXIT_SUCCESS 0
# define SCREEN_DEFAULT_WIDTH 1000
# define SCREEN_DEFAULT_HEIGHT 480
# define EYES_DEFAULT_X - 200
# define EYES_DEFAULT_Y 0
# define EYES_DEFAULT_Z 10
# define NB_BUTTONS 18
# define IMAGE_NAME "src/button.png"
# define SCENE_DEFAULT_X 0
# define SCENE_DEFAULT_Y 0
# define EMPTY - 1
# define NB_TOTAL_OBJECTS 4
# define OBJECT_ADDED 0
# define BUTTON_HIT 2
# define MOVED 2
# define SLAB_SIZE 4
# define MOVE_DISTANCE 0.2

typedef enum e_objects
  {
    sphere,
    cone,
    cyl,
    plane
  }	     t_e_objects;

typedef struct		s_object
{
  int			type;
  sfVector3f		position;
  sfColor		color;
  float			value;
  bool			is_damier;
  bool			is_transparent;
  bool			is_mirror;
  sfVector3f		rotation;
  float			(*intersect)(sfVector3f *, sfVector3f *, sfVector3f *, float);
  sfVector3f		(*normal)(sfVector3f, sfVector3f *, int);
}			t_object;

/*
** Utils
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
** Graphic types
*/

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  sfVector2i		dimensions;
}			t_my_framebuffer;

typedef t_my_framebuffer t_framebuffer;

typedef struct		s_inter
{
  float			inter;
  sfVector3f		point;
  t_object		*object;
}			t_inter;

typedef struct		s_light
{
  sfVector3f		coordinates;
  sfColor		color;
}			t_light;

typedef struct		s_button
{
  int			id;
  sfVector2f		position;
  sfVector2i		dimensions;
  sfColor		color;
  sfSprite		*sprite;
}			t_button;

typedef struct		s_screen
{
  sfVector2i		dimensions;
  sfVector3f		eyes;
  sfVector3f		rotate;
  sfVector3f		translate;
  t_framebuffer		framebuffer;
  t_listObject		objects;
  int			last_object;
  int			current_light;
  t_light		*lights;
  size_t		lights_count;
  t_button		*buttons;
  size_t		buttons_count;
  sfRenderWindow	*window;
  int			aliasing;
}			t_screen;

sfColor			get_my_color(t_object *object, t_screen *screen,
				     sfVector3f *inter_point, sfVector3f *dir_vector);
sfColor			get_real_color(sfColor color, float cos, sfColor obj_color);
int			compare_current_obj_and_other(t_object *current_obj, t_object other);
float			shadow(sfVector3f light_v, t_screen *screen, t_object *current_obj, sfVector3f *inter_point);
float			get_real_intersect(sfVector3f obj_pos, sfVector3f dir_vector,
					   float radius, int type);
/*
** Prototypes
*/
int			init_screen(t_screen *screen);
int			load_screen(t_screen *screen, char *filepath);
int			init_framebuffer(t_framebuffer *framebuffer);
sfVector3f	        sfVector3f_create(float x, float y, float z);
sfVector2i	        sfVector2i_create(int x, int y);
sfRenderWindow          *my_create_window(char *name, int width, int height);
void			show_window(t_screen *);
void		        print_gui(t_screen *screen);
//int	                set_button(t_button *buttons);
void			my_put_pixel(t_framebuffer *buffer, sfVector2i coords, sfColor color);
sfVector2f		sfVector2f_create(float, float);
int			check_button_hit(t_screen *, sfVector2i mouse);
int	                find_nearest_intersect(t_listObject *objects, sfVector3f *dir_vector, sfVector3f *eyes);
int			handle_poll_events(t_screen *screen);
void		        draw_objects(t_screen *);
t_object		init_object(int type);
int			add_object(t_listObject *objects, int type);
int			listObject_add(t_listObject *list, t_object object);
t_nodeObject            *listObject_getNode(t_listObject *list, int64_t id);
int		        listObject_remove(t_listObject *list, int64_t);
void		        listObject_reset_index(t_nodeObject *node);
float			intersect_sphere(sfVector3f *, sfVector3f *, sfVector3f *, float);
sfVector3f	        calc_dir_vector(sfVector2i screen_pos);
sfVector3f	        get_normal_vector(sfVector3f vector);
float		        get_root(float a, float b, float delt);
float		        intersect_plane(sfVector3f *dir_vector, sfVector3f *eye_pos, sfVector3f *, float);
float			intersect_cone(sfVector3f *dir_vector, sfVector3f *eye_pos,
				       sfVector3f *object, float radius);
float                   intersect_cyl(sfVector3f *dir_vector, sfVector3f *eye_pos,
				      sfVector3f *object, float radius);
int			listObject_init(t_listObject *list);
t_object	        get_object_to_draw(t_listObject *objects, int id);
float		        get_light_coef(sfVector3f *light_vector, sfVector3f *normal_vector);
sfVector3f		get_light_vector(sfVector3f *eye_pos, sfVector3f *dir_vector, sfVector3f *light_pos, float dist);
sfVector3f	        get_inter_point(sfVector3f *eye_pos, sfVector3f *dir_vector, float dist);
void			set_object(t_object *object, int type);
sfVector3f	        get_normal_sphere(sfVector3f inter, sfVector3f *obj_pos, int);
sfVector3f	        get_normal_plane(sfVector3f inter, sfVector3f *pos, int);
sfVector3f		get_normal_cylinder(sfVector3f inter, sfVector3f *pos, int);
sfVector3f	        get_normal_cone(sfVector3f intersection_point, sfVector3f *obj, int);
sfColor		        create_color(int r, int g, int b, int alpha);
void		        change_color(sfColor *color, float cos);
void			draw_pixel(t_screen *screen, sfVector2i *screen_pos, sfVector3f *dir_vector, t_object *object);
void		        init_lights(t_light *lights);
int		        move_objects(sfVector2i mouse_position, t_screen *screen);
void			clear_buffer(t_my_framebuffer *buffer, int width, int height);
sfVector2i	        calc_new_pos(sfVector2i mouse_position, sfVector2i new_position);
float		        move_x(float x);
int		        modify_color(t_screen *screen, int);
int		        is_cursor_on_button(sfVector2i mouse_position,
					    t_screen *screen, int i);
void		        print_scene(t_screen *screen, sfTexture *texture);
int		        button_action(t_screen *screen, int i);
sfVector3f	        rotate_xyz(sfVector3f to_rotate, sfVector3f angles);
sfVector3f		rotate_zyx(sfVector3f to_rotate, sfVector3f angles);
sfVector3f		translate(sfVector3f to_translate, sfVector3f translations);
int		        move_eye(sfVector3f *eyes);
int		        handle_movements(t_screen *screen);
int		        move_rotate(sfVector3f *rotate);
void		        set_buttons(t_button *buttons, sfSprite *sprite);
int			init_buttons(t_button *buttons);
int			move_light(t_screen *screen);
void			damier(sfVector3f *inter, sfColor *color);
sfVector3f		c_dir_vector(sfVector2i screen);
int			handle_movements(t_screen *screen);
int			change_damier(t_screen *screen);
void			change_light(t_screen *screen);
int			modify_size(t_screen *screen, int button_id);
sfVector3f		sfVector3f_cpy(sfVector3f src);
int             rotate_object(t_listObject *objects, int last_object_id);

#endif
