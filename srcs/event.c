/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:46:10 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/08/01 13:34:41 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	simple_zoom1(t_t *t)
{
	if (t->start_x < 0 && t->start_y < 0 && t->end_x > 0 && t->end_y > 0)
	{
		t->start_x = t->start_x + 0.015;
		t->start_y = t->start_y + 0.015;
		t->end_x = t->end_x - 0.015;
		t->end_y = t->end_y - 0.015;
	}
}

void	simple_zoom2(t_t *t)
{
	t->start_x = t->start_x - 0.040;
	t->start_y = t->start_y - 0.040;
	t->end_x = t->end_x + 0.040;
	t->end_y = t->end_y + 0.040;
}

void	init_x_y(t_t *t)
{
	t->x = ((t->x_x / (double)WIDTH)
			* (t->end_x - t->start_x)) + t->start_x;
	t->y = ((t->y_y / (double)HEIGHT)
			* (t->end_y - t->start_y)) + t->start_y;
}

void	string1_put(t_t *t)
{
	mlx_string_put(t->ptr, t->win, 650, 10, 0xFFFFFF,
		"-------------ZOOM-------------");
	mlx_string_put(t->ptr, t->win, 650, 40, 0x00ffaf,
		"            + | -              ");
	mlx_string_put(t->ptr, t->win, 650, 500, 0xFFFFFF,
		"------------Iteration---------");
	mlx_string_put(t->ptr, t->win, 650, 520, 0x00ffaf,
		"            + | -              ");
}

int	destroy_exit(t_t *t)
{
	mlx_destroy_image(t->ptr, t->image);
	mlx_destroy_window(t->ptr, t->win);
	exit(0);
}
