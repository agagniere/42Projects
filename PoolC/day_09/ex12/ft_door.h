/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 07:12:24 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/17 07:12:25 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H

# include <unistd.h>
# define CLOSE 0
# define OPEN 1
# define EXIT_SUCCESS 0
typedef int		t_bool;
typedef struct	s_door
{
	int			state;
}				t_door;

void			ft_putstr(char *str);
void			open_door(t_door *door);
void			close_door(t_door *door);
t_bool			is_door_open(t_door *door);
t_bool			is_door_close(t_door *door);

#endif
