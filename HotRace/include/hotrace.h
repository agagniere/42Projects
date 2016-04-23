/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:17:05 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/23 13:20:55 by angagnie         ###   ########.fr       */
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
}				t_ht_kv;

#endif
