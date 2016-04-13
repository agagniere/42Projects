/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 10:45:17 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/13 20:43:20 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 1024

typedef struct	s_fdsave
{
	t_node	self;
	int		fd;
	size_t	size;
	char	*data;
}				t_fdsave;

/*
** gnl :    N x A       ->  N x S
** |        (fd, &line) |-> (status, *line)
** -
** @param : fd : int            // File descriptor to read from.
** @param : line : char **      // The address of the output string.
** -
** @precondition : fd should already be opened
** @precondition : *line initial value should be NULL
** -
*/

int				get_next_line(int const fd, char **line);

#endif
