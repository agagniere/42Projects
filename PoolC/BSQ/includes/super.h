/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:56:33 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/30 17:21:00 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_H
# define SUPER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "structures.h"

# define TRUE 1
# define FALSE 0
# define EXIT_OK 0
# define EXIT_KO -1

int		is_ok(char *file_name);
int		copy_stdin(char *file_name);
t_int	ft_atoi(char *str);
int		ft_head_line(char *line, char *(stock[3]));
t_int	ft_cmp_line(char stock[3]);
int		ft_bsq(char *file_name);
void	malloc_fail();
t_int	max(t_int a, t_int b);
t_int	min(t_int tmp[3]);

t_dim	*new_dim(t_int	width, t_int height);
t_point	*new_point(t_int y, t_int x);
t_max	*new_max();
t_work	*new_work(char *str);
void	update_max(t_max *max, t_int value, t_point *p);
void	update_work_length(t_work *work);
void	destroy_work(t_work *work);

void	db_print_int(char *name, int var);
void	db_print_tint(char *name, t_int var);
void	db_print_str(char *name, char *var);
void	db_print_char(char *name, char var);

#endif
