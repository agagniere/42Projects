/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 14:59:43 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/26 22:50:51 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_H
# define SUPER_H

# include <unistd.h>
# include <stdlib.h>
# include "colors.h"
# include "form.h"
# include "ft_list.h"

# define TRUE 1
# define FALSE 0
# define NOT_A_SPACE -103

typedef long long int	t_int;
typedef int				t_bool;

char	*ft_strdup(char *src);
void	ft_putstr(char *str);
t_coord	*ft_read_stdin(char ***tab);
void	gooo(char **tab, t_coord *max);
t_bool	check_form(t_fun fct, char **tab, t_coord *max);
t_coord	*new_coordinate(int x, int y);

void	db_printint(char *name, int value);

#endif
