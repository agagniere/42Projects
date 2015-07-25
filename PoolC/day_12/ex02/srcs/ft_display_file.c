/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 15:30:46 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/24 23:38:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

void	ft_display_file(char *file_name, char *avzero, int c)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	int		n;

	fd = open(file_name, O_RDWR);
	db_printint("File Descriptor", fd);
	db_printint("Errno", errno);
	if (fd < 0)
	{
		ft_putstr_fd(STD_ERR, avzero);
		ft_putstr_fd(STD_ERR, ": ");
		ft_putstr_fd(STD_ERR, file_name);
		if (errno == 13)
			ft_putstr_fd(STD_ERR, ": Permission denied\n");
		if (errno == 21)
			ft_putstr_fd(STD_ERR, ": Is a directory\n");
		if (errno == 2)
			ft_putstr_fd(STD_ERR, ": No such file or directory\n");
	}
	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		write(STD_OUT, buffer, n);
	}
	db_printint("close 's return", close(fd));
}

void	ft_display_stdin(void)
{
	char	buffer[BUFFER_SIZE];
	int		n;

	while ((n = read(STD_IN, buffer, BUFFER_SIZE)) > 0)
	{
		write(STD_OUT, buffer, n);
	}
}
