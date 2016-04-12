/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 10:45:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/12 18:46:05 by angagnie         ###   ########.fr       */
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

static char 		*handle_past(t_fdsave *past, char **line)
{
	char	*ln;
	char	*tmp;

	if (past != NULL && (ln = ft_memchr(past->data, '\n', past->size)) != NULL)
	{
		*line = ft_memdup(past->data, ln - past->data + 1);
		*line[ln - past->data] = '\0';
		tmp = ft_memdup(ln + 1, past->size - (ln - past->data + 1));
		free(past->data);
		past->data = tmp;
	}
	return (past);
}

static int			now_read(t_fdsave *past, char **line)
{
	;
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

	if (line == NULL)
		return (-1);
	if (*line != NULL)	// Free previous line
	{
		free(*line);
		*line = NULL;
	}
	ft_dyna_datainit(&data);
	now_read(handle_past(get_past(fd, &save), line));
	return (1);
}
