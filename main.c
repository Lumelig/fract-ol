#include "fractol.h"
#include "libft/libft.h"

int main(int ac, char **av)
{
	t_fractol  fractol;

	if((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10))
	|| (4 == ac && !ft_strncmp(av[1], "julia", 5)))
	{
		fractol.name = av[1];
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx); 
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}