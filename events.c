#include "fractol.h"

void    clean_exit(t_fractol *fractol)
{
    if (fractol->img)
        mlx_delete_image(fractol->mlx, fractol->img);
    if (fractol->mlx)
        mlx_terminate(fractol->mlx);
    if (fractol)
        free(fractol);
        
    exit(0);
}

void    key_handler(mlx_key_data_t keydata, void *param)
{
    t_fractol *fractol;
    
    fractol = (t_fractol *)param;
    if (keydata.action == MLX_PRESS)
    {
        if (keydata.key == MLX_KEY_ESCAPE)
    		clean_exit(fractol);
        else if (keydata.key == MLX_KEY_UP)
            fractol->shift_y -= (0.5 * fractol->zoom);
        else if (keydata.key == MLX_KEY_DOWN)
            fractol->shift_y += (0.5 * fractol->zoom);
        else if (keydata.key == MLX_KEY_LEFT)
            fractol->shift_x -= (0.5 * fractol->zoom);
        else if (keydata.key == MLX_KEY_RIGHT)
            fractol->shift_x += (0.5 * fractol->zoom);
		else if (keydata.key == MLX_KEY_EQUAL || keydata.key == MLX_KEY_KP_ADD)
            fractol->iterations += 10;
        else if (keydata.key == MLX_KEY_MINUS || keydata.key == MLX_KEY_KP_SUBTRACT)
            fractol->iterations -= 10;
		fractol_render(fractol);
    }
}
void scroll_handler(double xdelta, double ydelta, void *param)
{
    t_fractol *fractol;
    
    fractol = (t_fractol *)param;
    if (ydelta > 0)
    {
        fractol->zoom *= 0.95;
        printf("Scrolling up: %f\n", ydelta);
    }
    else if (ydelta < 0)
    {
        fractol->zoom *= 1.05;
        printf("Scrolling down: %f\n", ydelta);
    }
    
    if (xdelta > 0)
    {
        fractol->zoom *= 0.95;
        printf("Scrolling right: %f\n", xdelta);
    }
    else if (xdelta < 0)
    {
        fractol->zoom *= 1.05;
        printf("Scrolling left: %f\n", xdelta);
    }
	fractol_render(fractol);
}
