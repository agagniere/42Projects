/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:44:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/24 01:48:37 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

# define NONE (void *)0xDEADBEEF

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

int		hm_add(t_hmap *m, t_hm_node *kv)
{
	t_hm_node	*cur;

	kv->hash = m->hash(kv) % m->capacity;
	if (m->capacity == 0)
		init(m);
	if (((t_hm_node *)(m->data + kv->hash * m->type_size))->next == NONE)
		hm_memcpy(m->data + kv->hash * m->type_size, kv, sizeof(*kv));
	else
	{
		if (!(cur = (t_hm_node *)hm_memdup(kv, sizeof(*kv))))
			return (1);
		cur->next = ((t_hm_node *)(m->data + kv->hash * m->type_size))->next;
		((t_hm_node *)(m->data + kv->hash * m->type_size))->next = cur;
	}
	return (0);
}

int		hm_get(t_hmap *m, t_hm_node *kv)
{
	kv->hash = m->hash(kv) % m->capacity;
	return (0);
}
