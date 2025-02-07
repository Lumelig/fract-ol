#include "fractol.h"

static uint32_t get_color(int i, int max_iterations)
{
	if (i == max_iterations)
        return (WHITE); 
    double t = (double)i / max_iterations;

    uint8_t r = (uint8_t)(9 * (1 - t) * t * t * t * 255);
    uint8_t g = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
    uint8_t b = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    
    return (255 << 24 | r << 16 | g << 8 | b);
}


static void	handel_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	uint32_t	color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;

	c.x = (map_scale(x, -2, +2, WIDTH) * fractol->zoom) + fractol->shift_x;
	c.y = (map_scale(y, +2, -2, HIGHT) * fractol->zoom) + fractol->shift_y;

	while (i < fractol->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = get_color(i, fractol->iterations);
			mlx_put_pixel(fractol->img, x, y, color);
			return ;
		}
		i++;
	}
	mlx_put_pixel(fractol->img, x, y, WHITE);
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
}