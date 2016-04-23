/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:17:05 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/24 00:30:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "hashmap.h"

typedef struct	s_hr_kv
{
	t_hm_node	node;
	char		*key;
	char		*value;
}				t_hr_kv;

/*
** -----=====  Equality function  =====-----
*/

int				hr_strequ(const t_hm_node *a, const t_hm_node *b);

/*
** -----=====  Hash Functions  =====-----
*/

size_t			hr_djb2(char *str);
size_t			hr_djb2a(char *str);
size_t			hr_sdbm(char *str);
size_t			hr_fnv1a(char *str);

#endif
