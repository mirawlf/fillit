/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:38:10 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/09 12:52:41 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"

int			free_detail(t_shape **detail)
{
	t_shape	*tmp;

	while (*detail)
	{
		tmp = (*detail);
		(*detail) = (*detail)->next;
		free(tmp);
	}
	return (0);
}

void		get_detail(const char *square, t_shape **detail)
{
	int		x;
	int		y;
	int		times;
	t_shape	*ret;
	int		i;

	x = 0;
	y = 0;
	times = 0;
	ret = *detail;
	i = 0;
	while (square[i])
	{
		if (square[i] == '\n')
		{
			y++;
			x = -1;
		}
		if (square[i++] == '#')
		{
			ret->coords[times][0] = x;
			ret->coords[times++][1] = y;
		}
		x++;
	}
}

int			main(int argc, char *argv[])
{
	int		fd;
	t_shape	*detail;
	char	*map;
	int		size;

	if (argc != 2)
		return (!write(0, "usage: ./fillit source_file\n", 28));
	if ((fd = open(argv[1], O_RDONLY)) >= 0)
		if ((detail = create_list(fd)))
			if (!(close(fd)) && ((fd = open(argv[1], O_RDONLY)) >= 0))
				if (is_normal(fd, &detail, &map, &size))
				{
					close(fd);
					normalize_list(&detail);
					settle(&map, detail, &size);
					write(1, map, size * size + size);
					free_detail(&detail);
					free(map);
					return (0);
				}
	write(1, "error\n", 6);
	(fd >= 0) ? free_detail(&detail) : 0;
	return (0);
}
