#include "fractol.h"

static void put_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color)
{
    uint32_t    *pixel_addr;

    // Check if pixel is within image bounds
    if (x >= img->width || y >= img->height)
        return;
        
    // Calculate the pixel position in the buffer
    // pixels[width * y + x] gives us the position in the 1D array
    pixel_addr = (uint32_t *)(img->pixels + (img->width * y + x) * sizeof(uint32_t));
    *pixel_addr = color;
}

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
static	void mandel_vs_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if(!ft_strncmp(fractol->name, "julia", 5))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handel_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	double		temp;
	uint32_t	color;

	i = 0;
	z.x = (map_scale(x, -2, +2, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.y = (map_scale(y, +2, -2, HIGHT) * fractol->zoom) + fractol->shift_y;

	mandel_vs_julia(&z, &c, fractol);
	while (i < fractol->iterations)
	{
		temp = z.x * z.x - z.y * z.y + c.x;
        z.y = 2 * z.x * z.y + c.y;
        z.x = temp;
		if((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = get_color(i, fractol->iterations);
			put_pixel(fractol->img, x, y, color);
			return ;
		}
		i++;
	}
	put_pixel(fractol->img, x, y, WHITE);
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