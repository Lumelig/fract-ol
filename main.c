#include "fractol.h"
#include "libft/libft.h"

int main(int ac, char **av)
{
	t_fractol  fractol;

	 // Checks if user entered correct arguments:
    // Either "./fractol mandelbrot" 
    // Or     "./fractol julia <value_1> <value_2>"
    // If not, shows error message
	if((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10))
	|| (4 == ac && !ft_strncmp(av[1], "julia", 5)))
	{
		//window name
		fractol.name = av[1];
		  // Sets up initial values:
    	// escape_value = 4 (determines when a point escapes the set)
    	// iterations = 42 (how many times to iterate each point)
		data_init(&fractol);
		 // Creates MLX window and image:
    	// - Initializes MLX with window size
    	// - Creates new image buffer
    	// - Attaches image to windo
		fractol_init(&fractol);
		// Converts screen coordinates to mathematical plane
	    // For Mandelbrot: typically range of -2 to +2
    	// Applies fractal formula (z = z² + c)
    	// Colors pixel based on how quickly point escapes
		fractol_render(&fractol);
		mlx_loop(fractol.mlx); 
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}