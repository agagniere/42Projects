/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 15:30:46 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/23 16:54:08 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

void	ft_display_file(char  *file_name)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	int		n;

	fd = open(file_name, O_RDONLY);
	db_printint("File Descriptor", fd);
	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		write(STD_OUT, buffer, n);
	}
	db_printint("close 's return", close(fd));
}
