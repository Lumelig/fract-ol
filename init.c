#include "fractol.h"

static void	malloc_error()
{
	perror("Problem with malloc");
	exit(EXIT_FAILURE);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection;
	if(NULL == fractol->mlx_connection)
		malloc_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH, HIGHT, fractol->name);
	if (NULL == fractol->mlx_window)
	{
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		malloc_error();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection, WIDTH, HIGHT);

	if(NULL == fractol->img.img_ptr)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		malloc_error();
	}
	fractol->img.pixel_ptr = mlx_get_data_addr(fractol->img.img_ptr, &fractol->img.bpp, &fractol->img.line_len, &fractol->img.endian);

}