/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:44:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/23 18:00:21 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

# define NONE 0xDEADBEEF

int		init(t_hmap *m)
{
	size_t		n;

	n = HM_INITIAL_SIZE;
	if (!(m->data = malloc(m->type_size * n)))
		return (1);
	m->capacity = n;
	while (n-- > 0)
		((t_hm_node *)(m->data + n * m->type_size))->next = NONE;
	return (0);
}

int		hm_add(t_hmap *m, const t_hm_node *kv)
{
	t_hm_node	*cur;

	kv->hash = m->hash(kv);
	if (m->capacity == 0)
		init(m);
	if (((t_hm_node *)(m->data + kv->hash * m->type_size))->next == NONE)
		hm_memcpy(m->data + kv->hash * m->type_size, kv, sizeof(kv));
	else
		cur = hm_memdup();
//		target = (t_hm_node *)malloc(m->type_size);
}

int		hm_get()
{

}
