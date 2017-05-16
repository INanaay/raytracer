/*
** draw_objects.c for Project-Master in /home/NANAA/Projets/raytracer2/src/tracing
**
** Made by NANAA
** Login   <nathan.lebon@epitech.eu>
**
** Started on  Fri Apr 14 15:51:23 2017 NANAA
** Last update Tue May 16 16:28:19 2017 anatole zeyen
*/

#include "raytracer.h"
#define NBR_COLORS screen->lights_count

sfColor	get_real_color(sfColor color, float cos, sfColor obj_color)
{
  if (color.r == 255 && color.g == 255 && color.b == 255)
    return (obj_color);
  color.r = (color.r * cos) / 2 + (obj_color.r * cos) / 2;
  color.g = (color.g * cos) / 2 + (obj_color.g * cos) / 2;
  color.b = (color.b * cos) / 2 + (obj_color.b * cos) / 2;
  return (color);
}

sfColor		get_my_color(t_object *object, t_screen *screen, sfVector3f *inter_point, sfVector3f *dir_vector)
{
  sfColor	color;
  sfColor	sumcolor;
  size_t	x;
  float		cos;
  sfVector3f	light_vector;
  float		inter;

  x = 0;
  inter = object->intersect(&(*dir_vector), &(screen->eyes),
			    &object->position, object->value);
  sumcolor = sfBlack;
  while (x != screen->lights_count)
    {
      color = screen->lights[x].color;
      light_vector = get_light_vector(&(screen->eyes), &(*dir_vector),
				      &(screen->lights[x].coordinates), inter);
      light_vector = get_normal_vector(light_vector);
      cos = get_light_coef(&light_vector, &(*inter_point));
      color = get_real_color(color, cos, object->color);
      sumcolor.r = sumcolor.r + (int)(color.r / NBR_COLORS);
      sumcolor.g = sumcolor.g + (int)(color.g / NBR_COLORS);
      sumcolor.b = sumcolor.b + (int)(color.b / NBR_COLORS);
      x++;
    }
  return (sumcolor);
}

sfColor         div_color_by_4(sfColor color)
{
  sfColor       new;

  if (color.r > 0)
    new.r = color.r / 4;
  else
    new.r = 0;
  if (color.g > 0)
    new.g = color.g / 4;
  else
    new.g = 0;
  if (color.b > 0)
    new.b = color.b / 4;
  else
    new.b = 0;
  return (new);
}

void		draw_pixel(t_screen *screen, sfVector2i *screen_pos, sfVector3f *dir_vector, t_object *object)
{
  sfVector3f	inter_point;
  sfVector3f	light_vector;
  float		cos;
  float		inter;
  sfColor	color_to_apply;
  sfVector3f	save_inter_point;

  inter = object->intersect(&(*dir_vector), &(screen->eyes), &object->position, object->value);
  inter_point = get_inter_point(&(screen->eyes), &(*dir_vector), inter);
  save_inter_point = inter_point;
  if (object->is_damier == true)
    damier(&inter_point, &object->color);
  inter_point = object->normal(inter_point, &(object->position), object->value);
  light_vector = get_light_vector(&(screen->eyes), &(*dir_vector), &(screen->lights[0].coordinates), inter);
  light_vector = get_normal_vector(light_vector);
  cos = get_light_coef(&light_vector, &inter_point);
  change_color(&(object->color), cos);
  object->color = get_my_color(object, screen, &inter_point, &(*dir_vector));
  if (shadow(light_vector, screen, object, &save_inter_point) == 0)
    my_put_pixel(&(screen->framebuffer), *screen_pos, div_color_by_4(object->color));
  else
    my_put_pixel(&(screen->framebuffer), *screen_pos, object->color);
}

int		find_nearest_intersect(t_listObject *objects, sfVector3f *dir_vector, sfVector3f *eyes)
{
  int		id;
  float		min;
  t_nodeObject	*node;
  size_t       	index;
  float		temp;

  min = 1000000;
  id = -1;
  if (objects->count == 0)
    return (id);
  node = objects->begin;
  id = 0;
  index = 0;
  while (index < objects->count)
    {
      temp = node->object.intersect(&(*dir_vector), &(*eyes), &node->object.position,
				    node->object.value);
      if (temp < min && temp > 0)
	{
	  id = index;
	  min = temp;
	}
      node = node->next;
      index++;
    }
  if (min == 1000000)
    return (- 1);
  return (id);
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

  screen_pos = sfVector2i_create(0, 0);
  while (screen_pos.y < FRAMEBUFFER_DEFAULT_HEIGHT)
    {
      screen_pos.x = 0;
      while (screen_pos.x < FRAMEBUFFER_DEFAULT_WIDTH)
	{
	  dir_vector = calc_dir_vector(screen_pos);
	  dir_vector = rotate_xyz(dir_vector, screen->rotate);
	  dir_vector = translate(dir_vector, screen->translate);
	  id = find_nearest_intersect(&(screen->objects), &dir_vector, &(screen->eyes));
	  if (id != -1)
	    {
	      obj = get_object_to_draw(&(screen->objects), id);
	      draw_pixel(&(*screen), &screen_pos, &dir_vector, &obj);
	    }
	  screen_pos.x++;
	}
      screen_pos.y++;
    }
}
