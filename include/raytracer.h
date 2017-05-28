/*
** ray.h for Project-Master in /home/NANAA/Projets/raytracer2/include
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Mon Apr 10 14:47:35 2017 NANAA
** Last update Sun May 28 19:02:52 2017 schwarzy
*/

#ifndef RAY_H_
# define RAY_H_

# include <SFML/Graphics.h>
# include <SFML/Window.h>
# include <stdbool.h>
# include <stdlib.h>

# define NBR_COLORS screen->lights_count
# define NAME "raytracer2"
# define FRAMEBUFFER_DEFAULT_WIDTH 1080
# define FRAMEBUFFER_DEFAULT_HEIGHT 720
# define WINDOW_DEFAULT_WIDTH 1700
# define WINDOW_DEFAULT_HEIGHT 720
# define BYTES_PER_PIXEL 4
# define BITS_PER_PIXEL 32
# define EXIT_ERROR 1
# define EXIT_SUCCESS 0
# define EYES_DEFAULT_X - 200
# define EYES_DEFAULT_Y 0
# define EYES_DEFAULT_Z 10
# define NB_BUTTONS 21
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
  sfVector3f		rotation;
  sfColor		color;
  float			value;
  float			spec;
  float			lim;
  bool			limited;
  bool			is_damier;
  bool			is_transparent;
  bool			is_mirror;
  float			(*intersect)(sfVector3f *, sfVector3f *,
				     sfVector3f *, float);
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
  sfVector3f		eyes;
  sfVector3f		dir_v;
  t_object		*object;
}			t_inter;

typedef struct		s_vlight
{
  sfVector3f		vl;
  sfVector3f		vln;
  float			cos;
}			t_vlight;

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
  char			*text;
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

/*
** Prototypes
*/

t_object	        get_object_to_draw(t_listObject *objects, int id);
t_object		init_object(int type);
t_nodeObject            *listObject_getNode(t_listObject *list, int64_t id);
void			set_for_rotation(sfVector3f *, sfVector3f *,
					 t_object *);
void		        draw_objects(t_screen *);
void			show_window(t_screen *);
void		        print_gui(t_screen *screen);
void			my_put_pixel(t_framebuffer *buffer, sfVector2i coords,
				     sfColor color);
void		        listObject_reset_index(t_nodeObject *node);
void			fill_black(t_my_framebuffer *buffer);
void			screenshot(t_my_framebuffer *buffer);
void			set_object(t_object *object, int type);
void		        change_color(sfColor *color, float cos);
void			draw_pixel(t_screen *screen, sfVector2i *screen_pos,
				   sfVector3f *dir_vector, t_object *object);
void		        init_lights(t_light *lights);

void			clear_buffer(t_my_framebuffer *buffer,
				     int width, int height);
void			change_light(t_screen *screen);
void		        print_scene(t_screen *screen, sfTexture *texture);
void		        set_buttons(t_button *buttons, sfSprite *sprite);
void			damier(sfVector3f *inter, sfColor *color);
bool			check_lim(float, t_object *,
				  sfVector3f *, sfVector3f *);
int			check_button_hit(t_screen *, sfVector2i mouse);
int	                find_nearest_intersect(t_listObject *objects,
					       sfVector3f *dir_vector,
					       sfVector3f *eyes);
int			handle_poll_events(t_screen *screen);
int			add_object(t_listObject *objects, int type);
int			listObject_add(t_listObject *list, t_object object);
int			listObject_init(t_listObject *list);
int		        move_objects(sfVector2i mouse_position,
				     t_screen *screen);
int			init_screen(t_screen *screen);
int			load_screen(t_screen *screen, char *filepath);
int			init_framebuffer(t_framebuffer *framebuffer);
int		        modify_color(t_screen *screen, int);
int		        is_cursor_on_button(sfVector2i mouse_position,
					    t_screen *screen, int i);
int		        button_action(t_screen *screen, int i);
int		        move_eye(sfVector3f *eyes);
int		        handle_movements(t_screen *screen);
int		        move_rotate(sfVector3f *rotate);
int			init_buttons(t_button *buttons);
int			move_light(t_screen *screen);
int			handle_movements(t_screen *screen);
int			change_damier(t_screen *screen);
int			modify_size(t_screen *screen, int button_id);
int			rotate_object(t_listObject *objects,
				      int last_object_id);
int			deserialize(t_screen *screen,
				    const char *save_path);
int			serialize(t_screen *screen,
				  const char *save_path);
int			modify_limit(t_screen *screen,
				     int button_id);
int		        listObject_remove(t_listObject *list, int64_t);
float			multilight_shadow(t_inter, t_screen *);
float			get_real_intersect(sfVector3f obj_pos,
					   sfVector3f dir_vector,
					   float radius, int type);
float			intersect_sphere(sfVector3f *, sfVector3f *,
					 sfVector3f *, float);
float		        get_root(float a, float b, float delt);
float		        intersect_plane(sfVector3f *dir_vector,
					sfVector3f *eye_pos,
					sfVector3f *, float);
float			intersect_cone(sfVector3f *dir_vector,
				       sfVector3f *eye_pos,
				       sfVector3f *object, float radius);
float                   intersect_cyl(sfVector3f *dir_vector,
				      sfVector3f *eye_pos,
				      sfVector3f *object, float radius);
float		        get_light_coef(sfVector3f *light_vector,
				       sfVector3f *normal_vector);
sfColor			divide_color(sfColor, int);
sfColor			sum_colors(sfColor, sfColor, int);
sfColor			diffuse_color(sfColor, float, sfColor, float);
sfColor		        create_color(int r, int g, int b, int alpha);
sfVector2i	        calc_new_pos(sfVector2i mouse_position,
				     sfVector2i new_position);
sfVector2i	        sfVector2i_create(int x, int y);
sfVector2f		sfVector2f_create(float, float);
sfVector3f	        sfVector3f_create(float x, float y, float z);
sfVector3f	        calc_dir_vector(sfVector2i screen_pos);
sfVector3f	        get_normal_vector(sfVector3f vector);
sfVector3f		get_light_vector(sfVector3f *eye_pos,
					 sfVector3f *dir_vector,
					 sfVector3f *light_pos,
					 float dist);
sfVector3f	        get_inter_point(sfVector3f *eye_pos,
					sfVector3f *dir_vector, float dist);
sfVector3f	        get_normal_sphere(sfVector3f inter,
					  sfVector3f *obj_pos, int);
sfVector3f	        get_normal_plane(sfVector3f inter,
					 sfVector3f *pos, int);
sfVector3f		get_normal_cylinder(sfVector3f inter,
					    sfVector3f *pos, int);
sfVector3f	        get_normal_cone(sfVector3f intersection_point,
					sfVector3f *obj, int);
sfVector3f	        rotate_xyz(sfVector3f to_rotate, sfVector3f angles);
sfVector3f		rotate_zyx(sfVector3f to_rotate, sfVector3f angles);
sfVector3f		translate(sfVector3f to_translate,
				  sfVector3f translations);
sfVector3f		inv_trans(sfVector3f, sfVector3f);
sfVector3f		c_dir_vector(sfVector2i screen);
sfVector3f		sfVector3f_cpy(sfVector3f src);
sfVector3f		apply_rotation(sfVector3f vector, sfVector3f rotation);
sfRenderWindow          *my_create_window(char *name, int width, int height);
sfText			*create_text();

#endif
