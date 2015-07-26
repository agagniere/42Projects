/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formtab.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 13:22:21 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/26 23:39:40 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMTAB_H
# define FORMTAB_H

# include "form.h"

t_form	g_formtab[] =
{
	{"colle-00", &colle_00_0},
	{"colle-01", &colle_00_1},
	{"colle-02", &colle_00_2},
	{"colle-03", &colle_00_3},
	{"colle-04", &colle_00_4},
	{"rectangle", &rectangle},
	{"triangle", &triangle_a},
	{"aucune", 0}
};

#endif
