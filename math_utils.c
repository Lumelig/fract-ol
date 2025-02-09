#include "fractol.h"

double map_scale(double unscaled_num, double new_min, double new_max, double old_max)
{
    return (new_max - new_min) * (unscaled_num / old_max) + new_min;
}

double atodbl (char *s)
{
	long integer_part;
	double fractional_part;
	double pow;
	int sign;
	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s ||'-' == *s)
		if ( '-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) *pow;
	}
	return ((integer_part + fractional_part) * sign);
}