/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 10:45:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/05 12:59:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

t_fdsave		*get_past(t_list *save)
{
	t_node	*tmp;
	fd_save	**data;
	char	*pos;

	data = &tmp;
	tmp = save;
	while ((tmp = tmp->next) != (t_node *)save)
	{
		if ((*data)->fd == fd)
		{
			if (pos = strchr())
			return (*data);
		}
	}
	return (NULL);
}

int		get_next_line(int const fd, char **line)
{
	static t_list	save;
	t_fdsave		*past;
	t_dyna			data;

	if (*line != NULL)	// Free previous line
	{
		free(*line);
		*line = NULL;
	}
	if ((past = get_past(fd, &save)) && handle_past(past, line))
		return (1);
	data = ft_dyna_new(sizeof(char));
	ft_dyna_datainit(&data);

	handle_past(fd, line,);
	return (0);
}
