/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:40:44 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/09 10:50:29 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrt(int nb)
{
	int		i;

	i = 0;
	while (i <= nb)
	{
		if (i * i >= nb)
			return (i);
		i++;
	}
	return (0);
}

char		*erect_map(int size)
{
	int		i;
	int		times;
	char	*ret;

	if (!(ret = (char*)malloc(size * (size + 1) + 1)))
		return (NULL);
	i = 0;
	times = 0;
	while (times < size)
	{
		if (i == size)
		{
			*ret = '\n';
			times++;
			i = -1;
		}
		else
			*ret = '.';
		i++;
		ret++;
	}
	*ret = '\0';
	return (ret - (size * (size + 1)));
}
