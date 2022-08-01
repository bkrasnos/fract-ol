/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:37:12 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/08/01 13:36:28 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 600
# define HEIGHT 600

typedef struct s_t
{
	double			x;
	double			y;
	double			x_x;
	double			y_y;
	double			start_y;
	double			end_y;
	double			start_x;
	double			end_x;
	double			x_o;
	double			y_o;
	double			xtmp;
	double			ytmp;
	void			*ptr;
	void			*win;
	void			*image;
	int				itier;
	int				size_l;
	int				bpp;
	int				endian;
	int				index;
	int				zoom;
	int				stop;
	int				max;
	int				color;
	char			*name;
	unsigned char	*ch;

}	t_t;

void		mandelbrot(t_t *t);
int			str_cmp(char *s1, char *s2);
int			mouse_move(int x, int y, t_t *t);
int			mouse_press(int button, int x, int y, t_t *t);
int			key_press(int keycode, t_t *t);
void		julia(t_t *t);
void		menu(t_t *t);
void		itier_loop(t_t *t);
void		map(t_t *t);
double		ft_abs(double x);
void		key_press2(int keycode, t_t *t);
void		key_press3(int keycode, t_t *t);
void		key_press4(int keycode, t_t *t);
void		set_color(t_t *t, int color);
int			str_cmp(char *s1, char *s2);
void		check_ar(t_t *t);
void		init(t_t *t, char *str);
void		string_put(t_t *t);
void		zoom(t_t *t, double x, double y, double zoom);
void		mlx_ho(t_t *t);
void		simple_zoom1(t_t *t);
void		simple_zoom2(t_t *t);
void		init_x_y(t_t *t);
void		string1_put(t_t *t);
int			destroy_exit(t_t *t);

#endif