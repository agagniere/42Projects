/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:24:09 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/22 19:26:30 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "structures.h"

int			fi_read(char const *const file_name,
	t_tet tetrimini[26], int *const length);
int			fi_print(t_tet const tetrimini[26],
	int const side, int const length);
int			fi_solve(t_tet tetrimini[26], int *const side, int const length);

#endif
