/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 15:24:28 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/30 17:23:49 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

t_bool	is_inside(t_int max_y, t_int my_y, t_int max_v)
{
	if (my_y <= max_y && (max_y - my_y) < max_v)
		return (TRUE);
	else
		return (FALSE);
}

void	print(t_work *all, char *file_name, char *buffer)
{
	int const	fd = open(file_name, O_RDONLY);
	ssize_t		n;
	t_point		*h;

	h = new_point(0, 0);
	read(fd, buffer, all->to_be_skipped);
	while ((n = read(fd, buffer, all->map->width)) > 0)
	{
		if (is_inside(all->max->y, h->y, all->max->value))
		{
			h->x = 0;
			while (h->x < all->map->width - 1)
			{
				if (is_inside(all->max->x, h->x, all->max->value))
					buffer[h->x] = all->taken;
				h->x++;
			}
		}
		write(1, buffer, all->map->width);
		h->y++;
	}
	close(fd);
	destroy_work(all);
	free(buffer);
}

int		aux(t_work *all, char *buffer, t_int tmp[3], t_point *h)
{
	tmp[1] = 0;
	tmp[0] = 0;
	h->x = 0;
	while (h->x < all->map->width - 1)
	{
		if (buffer[h->x] != all->obstacle && buffer[h->x] != all->room)
			return (EXIT_KO);
		tmp[2] = tmp[1];
		tmp[1] = all->cur_line[h->x];
		all->cur_line[h->x] = (buffer[h->x]
			== all->obstacle ? 0 : 1 + min(tmp));
		if (all->cur_line[h->x] > all->max->value)
			update_max(all->max, all->cur_line[h->x], h);
		tmp[0] = all->cur_line[h->x++];
	}
	return (EXIT_OK);
}

int		next(t_work *all, char *file_name)
{
	int const	fd = open(file_name, O_RDONLY);
	char		*buffer;
	ssize_t		n;
	t_point		*h;
	t_int		tmp[3];

	if (!(buffer = (char *)malloc(max(all->to_be_skipped, all->map->width))))
		malloc_fail();
	h = new_point(0, 0);
	read(fd, buffer, all->to_be_skipped);
	while ((n = read(fd, buffer, all->map->width)) > 0)
	{
		if (buffer[n - 1] != '\n' || n != all->map->width
			|| aux(all, buffer, tmp, h) == EXIT_KO)
			return (EXIT_KO);
		h->y++;
	}
	if (h->y != all->map->height)
		return (EXIT_KO);
	close(fd);
	print(all, file_name, buffer);
	return (EXIT_OK);
}

int		ft_bsq(char *file_name)
{
	char		*ptr;
	int const	fd = open(file_name, O_RDONLY);
	char		*buffer;
	t_work		*all;

	if (fd == -1)
		return (EXIT_KO);
	if (!(buffer = (char *)malloc(100)))
		malloc_fail();
	ptr = buffer;
	while (read(fd, ptr, 1) > 0 && *ptr != '\n' && (ptr - buffer) < 100)
		ptr++;
	if (ptr - buffer == 100 || *ptr != '\n')
		return (EXIT_KO);
	*ptr = '\0';
	if (!(all = new_work(buffer)))
		return (EXIT_KO);
	all->to_be_skipped = ptr - buffer + 1;
	while (read(fd, buffer, 1) > 0 && *buffer != '\n')
		all->map->width++;
	all->map->width++;
	close(fd);
	free(buffer);
	update_work_length(all);
	return (next(all, file_name));
}
