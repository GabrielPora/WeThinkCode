/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 10:24:27 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/29 10:30:20 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	t_l			*a[3];
	static int	x;
	char		*p;
	char		n;
	int			v;

	x = 0;
	a[1] = 0;
	if (fd < 1)
		return (-1);
	while ((v = read(fd, &n, 1)) && v && (n != '\n' || (n == '\n' && !x)))
	{
		a[0] = (t_l *)malloc(sizeof(t_l));
		a[0]->t = n;
		a[0]->n = a[1];
		a[1] = a[0];
		x += 1;
	}
	p = (char *)malloc(x + 1);
	if (x > 0)
		p[x] = '\0';
	while (v && a[0] && a[0]->t > 0 && (p[--x] = a[0]->t))
		a[0] = a[0]->n;
	*line = p;
	return ((v != 0) * (-1 * (n != '\n' && n != 0) + 1 * (n == '\n')));
}
