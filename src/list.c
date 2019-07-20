/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:31:54 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/09 12:31:28 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		normalize_list(t_shape **det)
{
	t_shape	*detail;
	int		min_x;
	int		min_y;
	int		i;

	detail = *det;
	i = 0;
	while (detail)
	{
		min_x = detail->coords[0][0];
		min_y = detail->coords[0][1];
		while (++i < 4)
		{
			min_x > detail->coords[i][0] ? min_x = detail->coords[i][0] : 0;
			min_y > detail->coords[i][1] ? min_y = detail->coords[i][1] : 0;
		}
		i = -1;
		while (++i < 4)
		{
			detail->coords[i][0] -= min_x;
			detail->coords[i][1] -= min_y;
		}
		i = 0;
		detail = detail->next;
	}
}

t_shape		*create_list(int fd)
{
	int		count;
	char	tmp[600];
	t_shape	*ret;
	t_shape	*head;
	int		i;

	if ((count = read(fd, tmp, 600)) > 545)
		return (NULL);
	count = (count + 1) / 21;
	if (!count || !(ret = (t_shape*)malloc(sizeof(t_shape))))
		return (NULL);
	i = 0;
	while (++i < count)
	{
		if (!(ret->next = (t_shape*)malloc(sizeof(t_shape))))
		{
			(i == 1) ? (free_detail(&ret)) : (free_detail(&head));
			return (NULL);
		}
		if (i == 1)
			head = ret;
		ret = ret->next;
	}
	ret->next = NULL;
	return ((i == 1) ? (ret) : (head));
}
