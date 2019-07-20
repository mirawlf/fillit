/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:37:21 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/11 15:13:26 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			try_to_fit(char **map, t_shape *d, int s, int i)
{
	char	*str;

	str = *map;
	if ((d->coords[3][0] + (d->coords[3][1] * (s + 1) + i) < s * s + s) &&
			DOT(0, i) && DOT(1, i) && DOT(2, i) && DOT(3, i))
	{
		str[d->coords[0][0] + (d->coords[0][1] * (s + 1)) + i] = d->c;
		str[d->coords[1][0] + (d->coords[1][1] * (s + 1)) + i] = d->c;
		str[d->coords[2][0] + (d->coords[2][1] * (s + 1)) + i] = d->c;
		str[d->coords[3][0] + (d->coords[3][1] * (s + 1)) + i] = d->c;
		return (1);
	}
	return (0);
}

int			logic(char **map, t_shape *d, int size)
{
	int		i;
	char	*str;

	str = *map;
	i = 0;
	if (!d)
		return (1);
	while (str[i])
	{
		if (try_to_fit(map, d, size, i))
		{
			if (!logic(map, d->next, size))
			{
				str[d->coords[0][0] + (d->coords[0][1] * (size + 1)) + i] = '.';
				str[d->coords[1][0] + (d->coords[1][1] * (size + 1)) + i] = '.';
				str[d->coords[2][0] + (d->coords[2][1] * (size + 1)) + i] = '.';
				str[d->coords[3][0] + (d->coords[3][1] * (size + 1)) + i] = '.';
			}
			else
				return (1);
		}
		i++;
	}
	return (0);
}

void		settle(char **map, t_shape *detail, int *size)
{
	while (!logic(map, detail, *size))
	{
		free(*map);
		*map = NULL;
		*map = erect_map(++(*size));
	}
}
