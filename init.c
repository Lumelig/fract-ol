#include "fractol.h"

static void	malloc_error()
{
	perror("Problem with malloc");
	exit(EXIT_FAILURE);
}
void	data_init(t_fractol  *fractol)
{
	if (!fractol) // NULL check
	{
		fprintf(stderr, "Error: fractol structure is NULL\n");
		exit(EXIT_FAILURE);
	}
	fractol->escape_value  =  4;
	fractol->iterations = 42;
}
static void events_init(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx, &key_handler, fractol->mlx);
	mlx_scroll_hook(fractol->mlx, &scroll_handler, fractol->mlx);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init(WIDTH, HIGHT, fractol->name, false);
	if(NULL == fractol->mlx)
		malloc_error();


	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HIGHT);

	if(NULL == fractol->img)
	{
		mlx_terminate(fractol->mlx);
		malloc_error();
	}
	if(mlx_image_to_window(fractol->mlx, fractol->img, 0, 0) < 0)
	{
		mlx_delete_image(fractol->mlx, fractol->img);
		mlx_terminate(fractol->mlx);
		malloc_error();
	}
	events_init(fractol);
}