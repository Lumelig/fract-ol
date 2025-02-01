#include "fractol.h"

// static  void	my_pixel_put(int x, int y, t_img *img, int color)
// {
// 	int	offset;

// 	offset = (y * img->line_len) + (x * (img->bpp / 8));
// 	*(unsigned  int *)(img->pixel_ptr + offset) = color;
// }

static void	handel_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;

	c.x = map_scale(x, -2, +2, WIDTH);
	c.y = map_scale(y, +2, -2, HIGHT);

	while (i < fractol->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = map_scale(i, BLACK, WHITE, fractol->iterations);
			mlx_put_pixel(fractol->img, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fractol->img, x, y, PSYCHEDELIC_PURPLE);
}

void	fractol_render(t_fractol *fractol)
{
	int x;
	int y;

	y = -1;
	while (++y < HIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handel_pixel(x, y, fractol);
		}
		
	}
	mlx_image_to_window(fractol->mlx,fractol->img, 0, 0);
}