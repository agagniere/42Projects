/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 10:45:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/29 15:39:07 by angagnie         ###   ########.fr       */
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

int		get_next_line(int const fd, char **line)
{
	static t_list	save;
	t_fdsave		*past;

	if (*line != NULL)	// Free previous line
	{
		free(*line);
		*line = NULL;
	}

}
