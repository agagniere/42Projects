/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:21:45 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/16 12:00:18 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		remplis_line(char **line, char *lignes)
{
	char	*str;

	str = ft_strchr(lignes, '\n');
	if (str)
	{
		str[0] = 0;
		*line = ft_strdup(lignes);
		ft_memmove(lignes, &str[1], ft_strlen(&str[1]) + 1);
		return (1);
	}
	if (ft_strlen(lignes) > 0)
	{
		*line = ft_strdup(lignes);
		*lignes = 0;
		return (1);
	}
	ft_putstr(lignes);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*lignes;
	char		*temp;
	int			rr;

	if (fd < 0 || !line)
		return (-1);
	if (!lignes && !(lignes = ft_strnew(1)))
		return (-1);
	while (!ft_strchr(lignes, '\n'))
	{
		if ((rr = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		if (rr == 0)
			break ;
		buf[rr] = 0;
		temp = ft_strjoin(lignes, buf);
		free(lignes);
		lignes = temp;
	}
	return (remplis_line(line, lignes));
}
