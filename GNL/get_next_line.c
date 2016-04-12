/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 10:45:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/12 19:42:24 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		*line = ft_memdup(past->data, ln - past->data + 1);
		*line[ln - past->data] = '\0';
		len = past->size - (ln - past->data + 1);
		tmp = ft_memdup(ln + 1, len);
		free(past->data);
		past->data = tmp;
		past->size = len;
		return (1);
	}
	return (0);
}

static int			now_read(t_fdsave *past, char **line, t_dyna *acc, int const fd)
{
	char	buf[BUFF_SIZE];
	int		ret;

	while (ret = read(fd, ))
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
	t_fdsave		past;

	if (line == NULL || BUFF_SIZE <= 0 || fd < 0)
		return (-1);
	if (*line != NULL)	// Free previous line
	{
		free(*line);
		*line = NULL;
	}
	data = ft_dyna_new(sizeof(char));
	past = get_past(fd, &save);
	if (past != NULL)
	{
		if (handle_past(past, line))
			return (1);
		else if (past->)
		ft_dyna_append(&data, past->data);
	}
	now_read(line, &data);
	return (1);
}
