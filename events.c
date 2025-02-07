#include "fractol.h"

void    key_handler(mlx_key_data_t keydata, void *param)
{
    mlx_t    *mlx;
    
    mlx = param;
    if (keydata.action == MLX_PRESS)
    {
        if (keydata.key == MLX_KEY_ESCAPE)
        {
            mlx_terminate(mlx);
            exit(0);
        }
        else if (keydata.key == MLX_KEY_SPACE)
        {
            // Do something when SPACE is pressed
        }
        else if (keydata.key == MLX_KEY_W)
        {
            // Do something when W is pressed
        }
        // Add more keys as needed
    }
}
void scroll_handler(double xdelta, double ydelta, void *param)
{
    (void)param;  // If you don't use the param
    
    if (ydelta > 0)
    {
        // Scrolling up
        printf("Scrolling up: %f\n", ydelta);
    }
    else if (ydelta < 0)
    {
        // Scrolling down
        printf("Scrolling down: %f\n", ydelta);
    }
    
}