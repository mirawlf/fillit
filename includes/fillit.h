/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 11:29:24 by wstygg            #+#    #+#             */
/*   Updated: 2019/07/15 13:59:36 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# define DOT(n, i) str[d->coords[n][0] + (d->coords[n][1] * (s + 1)) + i] == '.'

typedef struct		s_shape
{

	int				coords[4][2];
	char			c;
	struct s_shape	*next;
}					t_shape;

void				normalize_list(t_shape **det);
void				settle(char **map, t_shape *detail, int *size);
int					try_to_fit(char **map, t_shape *detail, int size, int i);
int					logic(char **map, t_shape *detail, int size);
char				*erect_map(int size);
int					ft_sqrt(int nb);
void				get_detail(const char *square, t_shape **detail);
int					ft_strchr(const char *s, int i, int *ncount, int *dcount);
int					amount_of_neighbors(char const *square, const int i);
int					is_normal(int fd, t_shape **detail, char **map, int *size);
int					check_square(char *square, int is_end, int *was20);
int					on_error(char **square);
int					free_detail(t_shape **detail);
t_shape				*create_list(int fd);

#endif
