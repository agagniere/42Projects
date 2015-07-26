/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 14:41:47 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/26 22:37:39 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

char	*print_fail(void)
{
	ft_putstr("Malloc failed.\n");
	return (NULL);
}

t_coord	*new_coordinate(int x, int y)
{
	t_coord	*ans;

	if (!(ans = (t_coord *)malloc(sizeof(t_coord))))
		return (0);
	ans->x = x;
	ans->y = y;
	return (ans);
}

t_coord	*ft_read_stdin(char ***tab)
{
	char		*data;
	int			n_i_j[3];
	t_coord		*ans;

	if (!(data = (char *)malloc(sizeof(char) * 16384)))
		return (0);
	n_i_j[0] = read(0, data, 16384);
	data[n_i_j[0]] = '\0';
	n_i_j[1] = 0;
	while (n_i_j[1] < n_i_j[0] && data[n_i_j[1]] != '\n')
		n_i_j[1]++;
	ans = new_coordinate(n_i_j[1], n_i_j[0] / (n_i_j[1] + 1));
	if (!(*tab = (char **)malloc(sizeof(char *) * ans->y)))
		return (0);
	n_i_j[1] = -1;
	while (++n_i_j[1] < ans->y)
	{
		(*tab)[n_i_j[1]] = (char *)malloc(ans->x + 2);
		n_i_j[2] = -1;
		while (++n_i_j[2] < ans->x)
			(*tab)[n_i_j[1]][n_i_j[2]] =
				data[(ans->x + 1) * n_i_j[1] + n_i_j[2]];
		(*tab)[n_i_j[1]][n_i_j[2]] = 0;
	}
	return (ans);
}
