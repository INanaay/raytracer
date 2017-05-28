/*
** draw_objects.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Fri Apr 14 15:51:23 2017 NANAA
** Last update Sun May 28 16:09:05 2017 schwarzy
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
  light_coef = multilight_shadow(inters, screen, dir_vector);
  change_color(&object->color, light_coef);
  aliasing(screen, screen_pos, object);
}

int		check_lim(float inter, t_object *obj,
			  sfVector3f *eyes, sfVector3f *dir_v)
{
  sfVector3f	point;

  if (obj->limited)
    {
      point = get_inter_point(eyes, dir_v, inter);
      if (point.z < obj->position.z - obj->lim
	  || point.z > obj->position.z + obj->lim)
	return (EXIT_SUCCESS);
    }
  return (EXIT_ERROR);
}

int		find_nearest_intersect(t_listObject *objects,
				       sfVector3f *dir_vector, sfVector3f *eyes)
{
  int		id;
  sfVector2f	vars;
  t_nodeObject	*node;
  size_t       	index;
  sfVector3f	dir_v_c;
  sfVector3f	final;

  vars.y = 10000.0f;
  node = objects->begin;
  id = 0;
  index = -1;
  while (++index < objects->count)
    {
      dir_v_c = *dir_vector;
      final = *eyes;
      set_for_rotation(&dir_v_c, &final, &node->object);
      vars.x = node->object.intersect(&dir_v_c, &final,
				    &node->object.position, node->object.value);
      if (vars.x < vars.y && vars.x > 0.0f
	  && check_lim(vars.x, &node->object, &final, &dir_v_c))
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
