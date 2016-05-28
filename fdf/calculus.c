/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 09:35:58 by ggroener          #+#    #+#             */
/*   Updated: 2016/05/27 15:22:39 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_coord(t_win *win)
{
	int	i;
	int	j;

	j = 0;
	while (j < win->map_h)
	{
		i = 0;
		while (i < win->map_w)
		{
			calculate(win, &(win->map[j][i]));
			i++;
		}
		j++;
	}
	draw_map(win);
}

void	rotate_z(t_win *win, t_rp *rp)
{
	rp->px = rp->act_px * cos(win->angle) - rp->act_py * sin(win->angle);
	rp->py = rp->act_px * sin(win->angle) + rp->act_py * cos(win->angle);
	rp->pz = rp->act_pz;
}

void	rotate_y(t_win *win, t_rp *rp)
{
	rp->px = rp->act_px * cos(win->angle) + rp->act_pz * sin(win->angle);
	rp->py = rp->act_py;
	rp->pz = rp->act_px * -sin(win->angle) + rp->act_pz * cos(win->angle);
}

void	rotate_x(t_win *win, t_rp *rp)
{
	rp->px = rp->act_px;
	rp->py = rp->act_py * cos(win->angle) - rp->act_pz * sin(win->angle);
	rp->pz = rp->act_py * sin(win->angle) + rp->act_pz * cos(win->angle);
}

void	calculate(t_win *win, t_point *pt)
{
}
