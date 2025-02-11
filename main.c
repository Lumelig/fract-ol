/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:52:24 by jpflegha          #+#    #+#             */
/*   Updated: 2025/02/11 12:57:18 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

void	start_program(t_fractol	fractol)
{
	data_init(&fractol);
	fractol_init(&fractol);
	fractol_render(&fractol);
	mlx_close_hook(fractol.mlx, &close_hook, &fractol);
	mlx_loop(fractol.mlx);
	if (fractol.img)
		mlx_delete_image(fractol.mlx, fractol.img);
	mlx_terminate(fractol.mlx);
}

void	close_hook(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	clean_exit(fractol);
	exit(0);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)) || (4 == ac
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		fractol.name = av[1];
		if (4 == ac)
		{
			fractol.julia_x = atodbl(av[2]);
			fractol.julia_y = atodbl(av[3]);
		}
		else
		{
			fractol.julia_x = 0.0;
			fractol.julia_y = 0.0;
		}
		start_program(fractol);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
