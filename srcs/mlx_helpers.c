/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:42:49 by shuppert          #+#    #+#             */
/*   Updated: 2023/09/14 17:41:33 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	my_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	int	index;

	index = (y * fractal->line_length + x * (fractal->bits_per_pixel / 8));
	((fractal->adress))[index / (fractal->bits_per_pixel / 8)] = color;
}

int	init_minilibx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		return (0);
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Fractal");
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->adress = (int *)mlx_get_data_addr(fractal->img,
												&fractal->bits_per_pixel,
												&fractal->line_length,
												&fractal->endian);
	return (1);
}

int	key_press(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
		destroy_fractal(fractal);
	//printf("keycode: %i", keycode);
	return (0);
}

int	handle_zoom(int button, int x, int y, t_fractal *fractal)
{
	printf("x: %i, y: %i", x, y);
	if (button == 4)
	{
		fractal->zoom /= 1.1;
		fractal->offset_x += x / 10;
		fractal->offset_y += y / 10;
	}
	else if (button == 5)
	{
		fractal->zoom *= 1.1;
		fractal->offset_x += x / 10;
		fractal->offset_y += y / 10;
	}
	return (0);
}


//Implement moving with arrows.