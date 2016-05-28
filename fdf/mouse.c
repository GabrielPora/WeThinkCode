/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:15:55 by ggroener          #+#    #+#             */
/*   Updated: 2016/05/26 17:21:14 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	increase_pixel(t_win *win)
{
	win->pad_h = (win->pad_h + 1.2 <= 0) ? win->pad_h : win->pad_h + 1.2;
	erase(win);
}

void    decrease_pixel(t_win *win)
{
	win->pad_h = (win->pad_h - 1.2 <= 0) ? win->pad_h : win->pad_h - 1.2;
	erase(win);
}
