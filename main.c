#include "mlx/include/MLX42/MLX42.h"
#include <stdlib.h>

uint32_t	create_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	color_image(mlx_image_t *img)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color;

	x = 0;
	y = 0;
	color = create_color(230, 100, 100, 255);
	while (y < img->height)
	{
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
		x = 0;
	}
}

void	esc_key(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(mlx);
	}
	exit(0);
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(1920, 1080, "fract-ol", false);
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_image_to_window(mlx, img, 0, 0);
	color_image(img);
	mlx_key_hook(mlx, &esc_key, mlx);
	// INTERRUPTS the program at the exact time the key is pressed
	// mlx_loop_hook();	// gets executed ONCE EVERY LOOP. no interrupt.1
	mlx_loop(mlx); // main loop
}
