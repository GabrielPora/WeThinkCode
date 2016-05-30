/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 08:15:24 by ggroener          #+#    #+#             */
/*   Updated: 2016/05/30 09:54:47 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_win *win)
{
	calculate_coord(win);
	if (win->draw_type == PUT)
		mlx_put_image_to_window(win->init, win->win, win->img, 0, 0);
	if (win->legend_display)
		put_info_to_window(win);
	return (0);
}

int		key_hook(int keycode, t_win *win)
{
	if (keycode == 65451)
		zoom_map(win);
	if (keycode == 65453)
		zoomout_map(win);
	if (keycode == 65362)
		move_image_up(win);
	if (keycode == 65364)
		move_image_down(win);
	if (keycode == 65363)
		move_image_right(win);
	if (keycode == 65361)
		move_image_left(win);
	if (keycode == 112)
		para_projection(win);
	if (keycode == 105)
		iso_projection(win);
	if (keycode == 100)
		draw_method(win);
	if (keycode == 102)
		put_method(win);
	if (keycode == 111)
		vanilla_mode(win);
	key_hook2(keycode, win);
	return (0);
}

int		key_hook2(int keycode, t_win *win)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65450)
		rotate_left(win);
	if (keycode == 65455)
		rotate_right(win);
	if (keycode == 120)
		pivote_z(win);
	if (keycode == 99)
		pivote_y(win);
	if (keycode == 118)
		pivote_z(win);
	if (keycode == 104)
		hide_legend(win);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_win *win)
{
	if (button == 1)
		increase_pixel(win);
	if (button == 3)
		decrease_pixel(win);
	(void)x;
	(void)y;
	return (0);
}
