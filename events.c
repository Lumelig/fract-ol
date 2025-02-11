/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:02:03 by jpflegha          #+#    #+#             */
/*   Updated: 2025/02/11 13:20:04 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_exit(t_fractol *fractol)
{
	if (fractol->img)
	{
		mlx_delete_image(fractol->mlx, fractol->img);
		fractol->img = NULL;
	}
	if (fractol->mlx)
	{
		mlx_terminate(fractol->mlx);
		fractol->mlx = NULL;
	}
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			clean_exit(fractol);
			exit(0);
		}
		else if (keydata.key == MLX_KEY_UP)
			fractol->shift_y += (0.5 * fractol->zoom);
		else if (keydata.key == MLX_KEY_DOWN)
			fractol->shift_y -= (0.5 * fractol->zoom);
		else if (keydata.key == MLX_KEY_LEFT)
			fractol->shift_x -= (0.5 * fractol->zoom);
		else if (keydata.key == MLX_KEY_RIGHT)
			fractol->shift_x += (0.5 * fractol->zoom);
		else if (keydata.key == MLX_KEY_EQUAL || keydata.key == MLX_KEY_KP_ADD)
			fractol->iterations += 10;
		else if (keydata.key == MLX_KEY_MINUS
			|| keydata.key == MLX_KEY_KP_SUBTRACT)
			fractol->iterations -= 10;
		fractol_render(fractol);
	}
}

void	scroll_handler(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;
	int32_t		mouse_x;
	int32_t		mouse_y;
	double		zoom_factor;
	t_mouse_pos	mp;

	fractol = (t_fractol *)param;
	mlx_get_mouse_pos(fractol->mlx, &mouse_x, &mouse_y);
	mp.m_re = (map_scale(mouse_x, -2, +2, WIDTH) * fractol->zoom)
		+ fractol->shift_x;
	mp.m_im = (map_scale(mouse_y, +2, -2, HIGHT) * fractol->zoom)
		+ fractol->shift_y;
	if (ydelta > 0 || xdelta > 0)
		zoom_factor = 0.95;
	else
		zoom_factor = 1.05;
	fractol->zoom *= zoom_factor;
	fractol->shift_x = mp.m_re - (mp.m_re - fractol->shift_x) * zoom_factor;
	fractol->shift_y = mp.m_im - (mp.m_im - fractol->shift_y) * zoom_factor;
	fractol_render(fractol);
}
