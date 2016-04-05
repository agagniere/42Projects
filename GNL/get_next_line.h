/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 10:45:17 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/29 15:18:31 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 1024

typedef struct	s_fdsave
{
	t_node	self;
	int		fd;
	char	*data;
}				t_fdsave;

typedef struct	s_gnl
{
	char	buf[BUFF_SIZE];
	t_dyna	acc;
}				t_gnl;
