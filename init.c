/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:49:10 by jpflegha          #+#    #+#             */
/*   Updated: 2025/02/11 12:51:14 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Problem with malloc");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractol *fractol)
{
	if (!fractol)
	{
		fprintf(stderr, "Error: fractol structure is NULL\n");
		exit(EXIT_FAILURE);
	}
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
	fractol->escape_value = 4;
	fractol->iterations = 42;
}

static void	events_init(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx, &key_handler, fractol);
	mlx_scroll_hook(fractol->mlx, &scroll_handler, fractol);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx = mlx_init(WIDTH, HIGHT, fractol->name, true);
	if (NULL == fractol->mlx)
		malloc_error();
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HIGHT);
	if (NULL == fractol->img)
	{
		mlx_terminate(fractol->mlx);
		malloc_error();
	}
	if (mlx_image_to_window(fractol->mlx, fractol->img, 0, 0) < 0)
	{
		mlx_delete_image(fractol->mlx, fractol->img);
		mlx_terminate(fractol->mlx);
		malloc_error();
	}
	events_init(fractol);
}
