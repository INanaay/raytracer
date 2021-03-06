/*
** draw_objects.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Fri Apr 14 15:51:23 2017 NANAA
** Last update Sun May 28 20:03:42 2017 schwarzy
*/

#include "raytracer.h"

static void		aliasing(t_screen *screen, sfVector2i *screen_pos,
				 t_object *object)
{
  sfVector2i		to_reach;

  to_reach.x = screen_pos->x + screen->aliasing;
  while (to_reach.x > screen_pos->x)
    {
      to_reach.y = screen_pos->y + screen->aliasing;
      while (to_reach.y > screen_pos->y)
	{
	  my_put_pixel(&(screen->framebuffer), to_reach, object->color);
	  to_reach.y--;
	}
      to_reach.x--;
    }
}

void		draw_pixel(t_screen *screen, sfVector2i *screen_pos,
			   sfVector3f *dir_vector, t_object *object)
{
  t_inter	inters;
  float		light_coef;

  inters.eyes = screen->eyes;
  inters.dir_v = *dir_vector;
  set_for_rotation(&inters.dir_v, &inters.eyes, object);
  inters.inter = object->intersect(&inters.dir_v, &inters.eyes,
			    &object->position, object->value);
  inters.point = get_inter_point(&inters.eyes, &inters.dir_v,
				 inters.inter);
  inters.object = object;
  if (object->is_damier == true)
    damier(&inters.point, &object->color);
  light_coef = multilight_shadow(inters, screen);
  change_color(&object->color, light_coef);
  aliasing(screen, screen_pos, object);
}

int			find_nearest_intersect(t_listObject *objects,
				       sfVector3f *dir_vector,
				       sfVector3f *eyes)
{
  static int	id = 0;
  sfVector2f	vars;
  t_nodeObject	*node;
  size_t	index;
  sfVector3f	finals[2];

  finals[0] = *dir_vector;
  finals[1] = *eyes;
  vars.y = 10000.0f;
  node = objects->begin;
  index = -1;
  while (++index < objects->count)
    {
      set_for_rotation(&finals[0], &finals[1], &node->object);
      vars.x = node->object.intersect(&finals[0], &finals[1],
				    &node->object.position, node->object.value);
      if (vars.x < vars.y && vars.x > 0.0f
	  && check_lim(vars.x, &node->object, &finals[1], &finals[0]))
	{
	  id = index;
	  vars.y = vars.x;
	}
      node = node->next;
    }
  return ((id = (vars.y == 10000.0f) ? -1 : id));
}

t_object	get_object_to_draw(t_listObject *objects, int id)
{
  t_nodeObject	*temp;
  int		index;

  index = 0;
  temp = objects->begin;
  while (index != id)
    {
      temp = temp->next;
      index++;
    }
  return (temp->object);
}

void		draw_objects(t_screen *screen)
{
  sfVector2i	screen_pos;
  sfVector3f	dir_vector;
  int		id;
  t_object	obj;

  screen_pos.y = 0;
  while (screen_pos.y < FRAMEBUFFER_DEFAULT_HEIGHT)
    {
      screen_pos.x = 0;
      while (screen_pos.x < FRAMEBUFFER_DEFAULT_WIDTH)
	{
	  dir_vector = calc_dir_vector(screen_pos);
	  dir_vector = apply_rotation(dir_vector, screen->rotate);
	  id = find_nearest_intersect(&screen->objects,
				      &dir_vector, &screen->eyes);
	  if (id != -1)
	    {
	      obj = get_object_to_draw(&screen->objects, id);
	      draw_pixel(screen, &screen_pos, &dir_vector, &obj);
	    }
	  screen_pos.x = screen_pos.x + screen->aliasing;
	}
      screen_pos.y = screen_pos.y + screen->aliasing;
    }
}
