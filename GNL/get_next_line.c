/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 10:45:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/05 14:44:46 by angagnie         ###   ########.fr       */
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

/* static t_fdsave		*get_past(int const fd, t_list *save) */
/* { */
/* 	t_node	*tmp; */
/* 	fd_save	**data; */
/* 	char	*pos; */

/* 	data = &tmp; */
/* 	tmp = save; */
/* 	while ((tmp = tmp->next) != (t_node *)save) */
/* 	{ */
/* 		if (*data->fd == fd) */
/* 		{ */
/* 			if (pos = strchr(*data->data)) */
/* 				return (*data); */
/* 		} */
/* 	} */
/* 	return (NULL); */
/* } */

/* static int			now_read() */
/* { */

/* } */

int					get_next_line(int const fd, char **line)
{
	(void)fd;
	*line = ft_strdup("Hello :*");
/* 	static t_list	save; */
/* 	t_dyna			data; */

/* 	if (*line != NULL)	// Free previous line */
/* 	{ */
/* 		free(*line); */
/* 		*line = NULL; */
/* 	} */
/* 	if (get_past(fd, &save) && ) */
/* 	data = ft_dyna_new(sizeof(char)); */
/* 	ft_dyna_datainit(&data); */

/* 	handle_past(fd, line,);	 */
	return (1);
}
