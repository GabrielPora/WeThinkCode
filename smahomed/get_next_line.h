/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 09:37:50 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/22 10:22:50 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# define BUFF_SIZE 20
# include <libc.h>
# include <unistd.h>

typedef struct		s_l
{
	char			t;
	struct s_l		*n;
}					t_l;
int					get_next_line(const int fd, char **line);
#endif
