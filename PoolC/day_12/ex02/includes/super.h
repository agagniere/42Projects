/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 14:59:43 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/24 23:36:58 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_H
# define SUPER_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "colors.h"

# define STD_IN 0
# define STD_OUT 1
# define STD_ERR 2

# define BUFFER_SIZE 1024

void	ft_putstr_fd(int fd, char *str);
void	ft_display_file(char *file_name, char *avzero, int c);
void	ft_display_stdin(void);
int		ft_atoi(char *str);

void	db_printint(char *name, int value);

#endif
