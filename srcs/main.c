/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:46:15 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/08/10 13:55:06 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	menu(t_t *t)
{
	int		i;
	int		j;

	j = -1;
	while (++j < HEIGHT)
	{
		i = 599;
		while (++i < 1000)
		{
			t->index = (j * 1000 * 4) + (i * 4);
			t->ch[t->index] = 189;
			t->ch[t->index + 1] = 87;
			t->ch[t->index + 2] = 54;
			t->ch[t->index + 3] = 0;
		}
	}
	mlx_put_image_to_window(t->ptr, t->win, t->image, 0, 0);
	string1_put(t);
	string_put(t);
}

void	string_put(t_t *t)
{
	mlx_string_put(t->ptr, t->win, 650, 70, 0x00ffaf,
		"    Scroll UP | Scroll DOWN         ");
	mlx_string_put(t->ptr, t->win, 650, 110, 0xFFFFFF,
		"-------------MOVE------------");
	mlx_string_put(t->ptr, t->win, 650, 140, 0x00ffaf,
		"     Arrow UP | Arrow DOWN    ");
	mlx_string_put(t->ptr, t->win, 650, 180, 0x00ffaf,
		"  Arrow RIGHT | Arrow LEFT ");
	mlx_string_put(t->ptr, t->win, 650, 240, 0xFFFFFF,
		"--------CHANGE FRACTAL-------");
	mlx_string_put(t->ptr, t->win, 650, 280, 0x00ffaf,
		"   mandelbrot | BUTTON (3) ");
	mlx_string_put(t->ptr, t->win, 650, 310, 0x00ffaf,
		"  burningship | BUTTON (2) ");
	mlx_string_put(t->ptr, t->win, 650, 340, 0x00ffaf,
		"        julia | BUTTON (1) ");
	mlx_string_put(t->ptr, t->win, 650, 380, 0xFFFFFF,
		"---------CHANGE COLOR--------");
	mlx_string_put(t->ptr, t->win, 650, 410, 0x00ffaf,
		"         BUTTON (enter) ");
	mlx_string_put(t->ptr, t->win, 650, 440, 0xFFFFFF,
		"--------RESTART FRACTAL-------");
	mlx_string_put(t->ptr, t->win, 650, 470, 0x00ffaf,
		"         BUTTON (0) ");
}

void	init(t_t *t, char *str)
{
	t->start_x = -2;
	t->end_x = 2;
	t->start_y = -2;
	t->end_y = 2;
	t->x_o = -0.4;
	t->y_o = 0.6;
	t->zoom = 0;
	t->stop = 0;
	t->max = 40;
	t->color = 10;
	t->name = str;
}

void	check_ar(t_t *t)
{
	if (str_cmp(t->name, "mandelbrot") == 0)
		mandelbrot(t);
	else if (str_cmp(t->name, "burningship") == 0)
		mandelbrot(t);
	else if (str_cmp(t->name, "julia") == 0)
		julia(t);
	else
	{
		write(1, "usage: ./fractol <name>", 23);
	}
}

int	main(int ac, char *av[])
{
	t_t		t;

	if (ac == 2)
	{
		if (str_cmp(av[1], "mandelbrot") == 0
			|| str_cmp(av[1], "burningship") == 0
			|| str_cmp(av[1], "julia") == 0)
		{
			t.ptr = mlx_init();
			t.win = mlx_new_window(t.ptr, 1000, 600, "fractol");
			t.image = mlx_new_image(t.ptr, WIDTH + 400, HEIGHT);
			t.ch = (unsigned char *)mlx_get_data_addr(t.image, &t.bpp,
					&t.size_l, &t.endian);
		}
		init(&t, av[1]);
		check_ar(&t);
	}
	else
	{
		write(1, "usage: ./fractol <name>", 23);
	}
	return (0);
}
