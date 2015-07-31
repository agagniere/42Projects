/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 18:35:29 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/31 22:04:07 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root,
	void *data_ref, int (*cmpf)(void *, void *))
{
	void *potential;

	potential = 0;
	if (root->left)
		potential = btree_search_item(root->left, data_ref, cmpf);
	if (potential)
		return (potential);
	else if (!cmpf(root->item, data_ref))
		return (root->item);
	else if (root->right)
		return (btree_search_item(root->right, data_ref, cmpf));
	else
		return (0);
}
