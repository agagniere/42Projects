/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:21:58 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/21 16:50:03 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	fi_overall(char const *buf)
{
	int		i;
	int		j;
	int		n;
	int		c;

	i = 4;
	n = 0;
	c = 0;
	while (i-- > 0)
	{
		j = 3;
		while (j-- > 0)
		{
			if (buf[5 * i + j] == '#' && buf[5 * i + j + 1] == '#')
				c++;
			if (buf[5 * j + i] == '#' && buf[5 * (j + 1) + i] == '#')
				c++;
		}
	}
	i = 20;
	while (i-- > 0)
		if (buf[i] == '#')
			n++;
	return (n != 4 || (c != 4 && c != 3));
}

static void	trim(t_tet *const p)
{
	int i;

	while (p->line[0] == 0)
	{
		i = 0;
		while (++i < 4)
			p->line[i - 1] = p->line[i];
		p->line[3] = 0;
	}
	while (!(p->line[0] % 2) && !(p->line[1] % 2)
		&& !(p->line[2] % 2) && !(p->line[3] % 2))
	{
		i = 4;
		while (i-- > 0)
			p->line[i] >>= 1;
	}
}

static int	fi_check(char const buffer[21],
	t_tet *const tetrimino, int const max)
{
	int		c;

	c = 0;
	while (c < max)
	{
		if (c % 5 == 4 || c == 20)
		{
			if (buffer[c] != '\n')
				return (2);
		}
		else if ((buffer[c] != '#' && buffer[c] != '.'))
			return (1);
		else if (buffer[c] == '#')
			tetrimino->line[c / 5] |= (1 << c % 5);
		c++;
	}
	trim(tetrimino);
	return (fi_overall(buffer));
}

int			fi_read(char const *const file_name,
	t_tet tetrimini[26], int *const length)
{
	int		fd;
	int		ret;
	char	buffer[21];
	int		index;

	index = 0;
	ret = 21;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (1);
	while (ret == 21)
	{
		ret = read(fd, buffer, 21);
		if (ret < 20 || index > 25 || fi_check(buffer, tetrimini + index, ret))
		{
			index = -1;
			break ;
		}
		index++;
	}
	close(fd);
	if (index == -1)
		return (1);
	*length = index;
	return (0);
}
