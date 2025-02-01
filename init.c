#include "fractol.h"

static void	malloc_error()
{
	perror("Problem with malloc");
	exit(EXIT_FAILURE);
}
void	data_init(t_fractol  *fratol)
{
	fratol->escape_value  =  4;
	fratol->iterations = 42;
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init(WHITE, HIGHT, fractol->name, true);
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

}