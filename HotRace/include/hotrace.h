/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:17:05 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/24 23:41:12 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include "hashmap.h"

# define BUFF_SIZE 4096

typedef struct	s_hr_kv
{
	t_hm_node	node;
	char		*key;
	char		*value;
}				t_hr_kv;

typedef struct	s_reader_data
{
	char	buffer[BUFF_SIZE];
	char	*end;
	char	*start;
	t_hr_kv	elem;
	int		ret;
	int		key_val;
	size_t	offset;
}				t_reader_data;

/*
** -----=====	Equality function	=====-----
*/

int				hr_strequ(const t_hm_node *a, const t_hm_node *b);

/*
** -----=====	Hash Functions	=====-----
*/

size_t			hr_djb2(t_hr_kv *n);
size_t			hr_djb2a(t_hr_kv *n);
size_t			hr_sdbm(t_hr_kv *n);
size_t			hr_fnv1a(t_hr_kv *n);

/*
** -----=====  Useful functions  =====-----
*/

size_t			hr_strlen(char const *str);

#endif
