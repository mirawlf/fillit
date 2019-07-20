/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 11:30:09 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/15 14:43:57 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_strchr(const char *s, int i, int *ncount, int *dcount)
{
	while (s[i] != '#')
	{
		if (!s[i] || (s[i] != '.' && s[i] != '\n') || *ncount > 3)
			return (-1);
		if (s[i] == '\n')
			(*ncount)++;
		else if (s[i] == '.')
			(*dcount)++;
		i++;
	}
	return (i);
}

int			on_error(char **square)
{
	free(*square);
	*square = NULL;
	return (0);
}

int			amount_of_neighbors(char const *square, const int i)
{
	int		amount;

	amount = 0;
	amount += (i > 0 && square[i - 1] == '#');
	amount += (i > 4 && square[i - 5] == '#');
	amount += (i < 19 && square[i + 1] == '#');
	amount += (i < 15 && square[i + 5] == '#');
	return (amount);
}

int			check_square(char *square, int bytes, int *was20)
{
	int		amount;
	int		i;
	int		hcount;
	int		ncount;
	int		dcount;

	i = 0;
	amount = 0;
	ncount = 0;
	hcount = 0;
	dcount = 0;
	*was20 = (bytes == 20);
	while (square[i])
	{
		i = ft_strchr(square, i, &ncount, &dcount);
		if (i == -1)
			break ;
		hcount++;
		amount += amount_of_neighbors(square, i);
		i++;
	}
	if (square[bytes - 1] != '\n' || (amount != 6 && amount != 8)
			|| hcount != 4 || dcount != 12)
		return (0);
	return (1);
}

int			is_normal(int fd, t_shape **det, char **map, int *size)
{
	char	*square;
	int		times;
	int		bytes;
	int		was20;
	t_shape	*detail;

	times = -1;
	square = (char*)malloc(22);
	if (!square)
		return (0);
	detail = *det;
	while ((bytes = read(fd, square, 21)) > 0 && ++times < 26)
	{
		square[bytes] = '\0';
		if (bytes < 20 || !(check_square(square, bytes, &was20)))
			return (on_error(&square));
		get_detail(square, &detail);
		detail->c = 'A' + times;
		detail = detail->next;
	}
	*size = ft_sqrt((times + 1) * 4);
	if (!was20 || !(*map = erect_map(*size)))
		return (on_error(&square));
	free(square);
	return (1);
}
