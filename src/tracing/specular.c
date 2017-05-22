/*
** specular.c for  in /home/anatole.zeyen/raytracer2/src/tracing
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Mon May 22 15:52:27 2017 anatole zeyen
** Last update Mon May 22 16:07:15 2017 anatole zeyen
*/

sfVector3f	vector_reflect(sfVector3f *normal_light,
			       sfVector3f *normal_normal)
{
  sfVector3f	reflect_vector;

  reflect_vector.x = -2 * normal_normal.x * (normal_light.x * normal_normal.x)
    + normal_light.x;
  reflect_vector.y = -2 * normal_normal.y * (normal_light.y * normal_normal.y)
    + normal_light.y;
  reflect_vector.z = -2 * normal_normal.z * (normal_light.z * normal_normal.z)
    + normal_light.z;
  return (reflect_vector);
}

float		specular(sfVector3f dir_vector, sfVector3f *light,
			 float coef, sfVector3f *normal)
{
  float		angle;
  sfVector3f	normal_light;
  sfVector3f	normal_normal;

  normal_light = get_normal_vector(*light);
  normal_normal = get_normal_vector(*normal);
  normal_normal = get_normal_vector(vector_reflect(&normal_light,
						   &normal_normal));
  angle = dir_vctor.x * normal_normal.x + dir_vector.y *
    normal_normal.y + dir_vector.z * normal_normal.z;
  if (angle <= 0 || coef == 0 || angle >= 1)
    return (0);
  coef = 200;
  angle = pow(angle, coef);
  return (angle);
}
