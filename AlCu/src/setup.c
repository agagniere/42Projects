/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:07:42 by yaitalla          #+#    #+#             */
/*   Updated: 2015/12/21 01:24:11 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static int			iterstr(char *line)
{
	if (*line == '\0')
		return (1);
	return (ft_isdigit(*line) && iterstr(line + 1));
}

static int			check_line(char *line)
{
	int				i;

	i = ft_atoi(line);
	if ((i < 1 || i > 10000) || !iterstr(line))
		return (0);
	return (i);
}

int					initall(t_ai *all, int fd)
{
	char			*line;
	int				i;
	int				nb;

	i = 0;
	all->map = (int *)malloc(sizeof(int) * MAX_ROW);
	all->inverted = (int *)malloc(sizeof(int) * MAX_ROW);
	all->inverted[0] = 0;
	while (get_next_line(fd, &line) > 0 && (*line))
	{
		if ((nb = check_line(line)) == 0)
			return (1);
		else
		{
			all->map[i] = nb;
			if (i > 0)
				all->inverted[i] = !((all->map[i - 1] + 3) % 4);
		}
		i++;
	}
	all->map[i] = 0;
	all->lines = i;
	return (0);
}
