/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:44:27 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/30 21:07:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

#define BFSZ 8192

int		copy_stdin(char *file_name)
{
	int			fd;
	ssize_t		n;
	char		buffer[BFSZ];

	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	while ((n = read(0, buffer, BFSZ)) > 0)
		write(fd, buffer, n);
	return (EXIT_OK);
}
