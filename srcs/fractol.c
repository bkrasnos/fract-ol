/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:46:13 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/08/01 13:35:01 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia(t_t *t)
{
	mlx_clear_window(t->ptr, t->win);
	t->y_y = 0;
	while (t->y_y < WIDTH)
	{
		t->x_x = 0;
		while (t->x_x < HEIGHT)
		{
			t->itier = 0;
			init_x_y(t);
			itier_loop(t);
			if (t->itier == t->max)
				set_color(t, 0);
			else
				set_color(t, 1);
			t->x_x++;
		}
		t->y_y++;
	}
	mlx_ho(t);
}

void	mandelbrot(t_t *t)
{
	mlx_clear_window(t->ptr, t->win);
	t->y_y = 0;
	while (t->y_y < HEIGHT)
	{
		t->x_x = 0;
		while (t->x_x < WIDTH)
		{
			t->itier = 0;
			map(t);
			itier_loop(t);
			if (t->itier == t->max)
				set_color(t, 0);
			else
				set_color(t, 1);
			t->x_x++;
		}
		t->y_y++;
	}
	t->stop = 1;
	mlx_ho(t);
}

int	mouse_move(int x, int y, t_t *t)
{
	if (x < 600 && y < 600 && t->stop == 0 && str_cmp(t->name, "julia") == 0)
	{
		t->x_o = (((double)x / 600) * 4) - 2;
		t->y_o = ((((double)y * -1) / 600) * 4) + 2;
		check_ar(t);
	}
	return (1);
}

void	zoom(t_t *t, double x, double y, double zoom)
{
	double	xx;
	double	yy;

	xx = ((x / WIDTH) * (t->end_x - t->start_x)) + t->start_x;
	yy = ((y / HEIGHT) * (t->end_y - t->start_y)) + t->start_y;
	t->start_x = xx + ((t->start_x - xx) * zoom);
	t->start_y = yy + ((t->start_y - yy) * zoom);
	t->end_y = yy + ((t->end_y - yy) * zoom);
	t->end_x = xx + ((t->end_x - xx) * zoom);
	if (t->max <= 120)
		t->max += 2;
}

void	mlx_ho(t_t *t)
{
	menu(t);
	mlx_hook(t->win, 4, 1, mouse_press, t);
	mlx_hook(t->win, 6, 1, mouse_move, t);
	mlx_hook(t->win, 2, 1, key_press, t);
	mlx_hook(t->win, 17, 0L, destroy_exit, t);
	mlx_loop(t->ptr);
}
