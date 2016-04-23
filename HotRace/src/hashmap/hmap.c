/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:44:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/23 21:19:53 by angagnie         ###   ########.fr       */
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
		hm_memcpy(m->data + kv->hash * m->type_size, kv, sizeof(*kv));
	else
	{
		cur = (t_hm_node *)hm_memdup(kv, sizeof(*kv));
		cur->next = ((t_hm_node *)(m->data + kv->hash * m->type_size))->next;
		((t_hm_node *)(m->data + kv->hash * m->type_size))->next = cur;
	}
}

int		hm_get()
{

}
