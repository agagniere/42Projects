/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 10:45:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/13 21:12:21 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define ACCSIZE (acc->chunck_count)

static t_fdsave		*get_past(int const fd, const t_list *save)
{
	t_node	*tmp;

	tmp = (t_node *)save;
	while ((tmp = tmp->next) != (t_node *)save)
		if (((t_fdsave *)tmp)->fd == fd)
			return ((t_fdsave *)tmp);
	return (NULL);
}

static int			handle_past(t_fdsave *past, char **line)
{
	char	*ln;
	char	*tmp;
	size_t	len;

	if (past != NULL && (ln = ft_memchr(past->data, '\n', past->size)) != NULL)
	{
		*line = ft_memdup(past->data, ln - (char *)past->data + 1);
		(*line)[ln - past->data] = '\0';
		len = past->size - (ln - (char *)past->data + 1);
		tmp = ft_memdup(ln + 1, len);
		free(past->data);
		past->data = tmp;
		past->size = len;
		return (1);
	}
	return (0);
}

static int			gnl2(int ret, t_dyna *acc, char **line)
{
	if (ret < 0)
	{
		ft_dyna_del(acc);
		return (-1);
	}
	if (ACCSIZE > 0)
	{
		*line = ft_memdup(acc->data, ACCSIZE + 1);
		(*line)[ACCSIZE] = '\0';
		return (1);
	}
	ft_dyna_del(acc);
	return (0);
}

static int			now_read(char **line, t_dyna *acc,
	int const fd, t_list *save)
{
	char	buf[BUFF_SIZE];
	char	*ln;
	int		ret;
	int		len;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_dyna_append(acc, buf, ret);
		ln = ft_memchr((char *)acc->data + ACCSIZE - ret, '\n', ret);
		if (ln != NULL)
		{
			len = ((char *)(acc->data) + ACCSIZE) - ln - 1;
			*line = ft_memdup(acc->data, ln - (char *)(acc->data) + 1);
			*(*line + (ln - (char *)(acc->data))) = '\0';
			if (len > 0)
				ftl_push_back(save, (t_node *)&(t_fdsave){{0, 0}, fd,
					len, ft_memdup(ln + 1, len)});
			ft_dyna_del(acc);
			return (1);
		}
	}
	return (gnl2(ret, acc, line));
}

/*
** gnl :	N x A		->	N x S
** |		(fd, &line)	|->	(status, *line)
** -
** @param :	fd : int			// File descriptor to read from.
** @param :	line : char **		// The address of the output string.
** -
** @precondition : fd should already be opened
** @precondition : *line initial value should be NULL
** -
** @local :	save : List<Fdsave>	// All fds' leftovers
** @local :	past : Fdsave *		// Current fd's leftovers
** -
*/

int					get_next_line(int const fd, char **line)
{
	static t_list	save;
	t_dyna			data;
	t_fdsave		*past;

	if (line == NULL || BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	data = ft_dyna_new(sizeof(char));
	ft_dyna_datainit(&data);
	if (save.size != 0 && (past = get_past(fd, &save)) != NULL)
	{
		past = get_past(fd, &save);
		if (handle_past(past, line))
			return (1);
		ft_dyna_append(&data, past->data, past->size);
		ftl_pop_elem(&save, (t_node **)&past);
	}
	else if (save.type_size == 0)
		ftl_init(&save, sizeof(t_fdsave));
	return (now_read(line, &data, fd, &save));
}

/*
**	--== I planned to add ==--
**	if (*line != NULL)	// Free previous line
**	{
**		free(*line);
**		*line = NULL;
**	}
**	--======================--
*/
