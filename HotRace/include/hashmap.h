/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:21:18 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/24 01:48:58 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include <stdlib.h>

typedef struct	s_hmap
{
	void		*data;
	size_t		capacity;
	size_t		size;
	size_t		type_size;
	int			(*equal)();
	size_t		(*hash)();
}				t_hmap;

typedef struct	s_hm_node
{
	struct s_hm_node	*next;
	size_t				hash;
}				t_hm_node;

# define HM_INITIAL_SIZE 5000000

/*
** -----=====  Constructor  =====-----
*/

# define NEW_HMAP(ELEM_SZ, FNC_EQUAL, FNC_HASH)		\
	(t_hmap){0, 0, 0, ELEM_SZ, FNC_EQUAL, FNC_HASH}

/*
** -----=====  Member Functions  =====-----
*/

int		hm_init(t_hmap *m);
int		hm_add(t_hmap *m, t_hm_node *kv);
int		hm_get(t_hmap *m, t_hm_node *kv);

/*
** -----=====  Helpful functions (for internal usage)  =====-----
*/

void	*hm_memcpy(void *dst, const void *src, size_t len);
void	*hm_memdup(const void *src, size_t len);

#endif
