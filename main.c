#include "fractol.h"
#include "libft/libft.h"

int main(int ac, char **av)
{
	if((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10))
	|| (4 == ac && !ft_strncmp(av[1], "julia", 5)))
	{
		window();

	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}