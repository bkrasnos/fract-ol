/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:46:17 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/07/07 13:33:17 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	set_color(t_t *t, int color)
{
	t->index = (4 * 1000 * t->y_y) + t->x_x * 4;
	t->ch[t->index] = (t->itier * t->color + 200 + 0 + 255) * color;
	t->ch[t->index + 1] = (t->itier * t->color + 0 + 0 + 255) * color;
	t->ch[t->index + 2] = (t->itier * t->color + 0 + 103 + 255) * color;
	t->ch[t->index + 3] = 0;
}

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	map(t_t *t)
{
	t->x = t->x_x / (WIDTH / (t->end_x - t->start_x)) + t->start_x;
	t->y = t->y_y / (HEIGHT / (t->end_y - t->start_y)) + t->start_y;
	t->x_o = t->x;
	t->y_o = t->y;
}

void	itier_loop(t_t *t)
{
	while (t->itier < t->max)
	{
		t->xtmp = t->x * t->x - t->y * t->y;
		if (str_cmp(t->name, "burningship") == 0)
			t->ytmp = ft_abs(2 * t->x * t->y);
		else
			t->ytmp = 2 * t->x * t->y;
		t->x = t->xtmp + t->x_o;
		t->y = t->ytmp + t->y_o;
		if (t->x * t->x + t->y * t->y > 4)
			break ;
		t->itier++;
	}
}
