/*
** utils.c for raytracer in /home/flavian.gontier/Tek1/C_Graphical/raytracer2/src/tracing
** 
** Made by flavian gontier
** Login   <flavian.gontier@epitech.eu@epitech.net>
** 
** Started on  Tue Apr 11 11:58:46 2017 flavian gontier
** Last update Tue Apr 11 12:13:36 2017 flavian gontier
*/

void	my_put_pixel(t_framebuffer *buffer, sfVector2i coords, sfColor color)
{
  int	index;
  int	height;

  if (coords.x >= buffer.dimensions.x || coords.x < 0)
    return ;
  if (coords.y >= buffer.dimensions.y || coords.y < 0)
    return ;
  index = (buffer.dimensions.x * coords.y) + coords.x;
  buffer->pixels[index] = sfColor.r;
  buffer->pixels[index + 1] = sfColor.g;
  buffer->pixels[index + 2] = sfColor.b;
  buffer->pixels[index + 3] = sfColor.a;
}
