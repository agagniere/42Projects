/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 15:28:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/26 16:58:04 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFF_SIZE 1024

char	*sp_strjoin(char *a, char *b, int lb)
{
	const size_t	la = ft_strlen(a);
	char *const		ans = ft_strnew(la + lb);

	ft_memcpy(ans, a, la);
	ft_memcpy(ans + la, b, lb);
	free(a);
	return (ans);
}

int		get_next_line(int const fd, char **line)
{
	static char		*save;
	char			*buf;
	char			*pos;
	size_t			i;
	int				ret;

	i = 0;
	ret = 0;
	if (!(buf = ft_strnew(BUFF_SIZE))
		|| (save == NULL && !(save = ft_strnew(0))))
		return (-1);
	while ((pos = ft_strchr(save + i, '\n')) == NULL && (i += ret) >= 0
		&& (ret = read(fd, buf, BUFF_SIZE)) > 0)
		save = sp_strjoin(save, buf, ret);
	if (pos != NULL)
	{
		*line = ft_memdup(save, pos - save + 1);
		*line[pos - save] = 0;
	}
	free(buf);
	if (ret < 0)
		return (-1);
}

int		main(int ac, char **av)
{
	char	*line = NULL;

	get_next_line(0, &line);
	ft_putstr("-> ");
	ft_putstr(line);
	ft_putstr("\\\n");
	return (0);
}
