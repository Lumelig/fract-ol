#ifndef 	FRACTOL_H
#define		FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mlx/include/MLX42/MLX42.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\""

#define WIDTH 800
#define HIGHT 800

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp; //bites per pixel
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
}			t_fractol;

void	fractol_init(t_fractol *fractol);

int	window(void);

#endif