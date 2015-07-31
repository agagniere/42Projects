/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 18:03:50 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/25 18:07:02 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree *ans;

	if (!(ans = (t_btree *)malloc(sizeof(t_btree))))
		return (0);
	ans->item = item;
	ans->right = 0;
	ans->left = 0;
	return (ans);
}
