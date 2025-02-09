#ifndef 	FRACTOL_H
#define		FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mlx/include/MLX42/MLX42.h"
#include "libft/libft.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\""

#define WIDTH 1000
#define HIGHT 800

#define BLACK 0x000000 // RGB(0, 0, 0 )
#define WHITE 0xFFFFFF // RGB(255, 255, 255)
#define RED 0xFF0000 // RGB(255, 0, 0)
#define GREEN 0x00FF00 // RGB(0, 255, 0)
#define BLUE 0x0000FF // RGB(0, 0, 255)
#define MAGENTA 0xFF00FF // A vibrant magenta
#define LIME_SHOCK 0xCCFF00 // A blinding lime
#define NEON_ORANGE 0xFF6600 // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066 // A deep purple
#define AQUA_DREAM 0x33CCCC // A bright turquoise
#define HOT_PINK 0xFF66B2 // As the name suggests
#define ELECTRIC_BLUE 0x0066FF // A radiant blue
#define LAVA_RED 0xFF3300 // A bright, molten red

typedef struct s_complex
{
	// real
	double	x;
	// i
	double	y;
}		t_complex;


typedef struct s_fractol
{
	char	*name;
	mlx_t	*mlx;
	mlx_image_t *img;
	double	escape_value;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractol;

void	data_init(t_fractol  *fractol);

void	fractol_init(t_fractol *fractol);
//This is a linear mapping (scaling) function that transforms a value from one range to another
double map_scale(double unscaled_num, double new_min, double new_max, double old_max);

void	key_handler(mlx_key_data_t keydata, void *param);

void	fractol_render(t_fractol *fractol);

void scroll_handler(double xdelta, double ydelta, void *param);

void    clean_exit(t_fractol *fractol);

double atodbl (char *s);

void close_hook(void *param);

int	window(void);

#endif