/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 22:41:50 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/25 23:25:37 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int		btree_level_count(t_btree *root)
{
	int		l;
	int		r;

	l = 0;
	r = 0;
	if (root->left)
		l = btree_level_count(root->left);
	if (root->right)
		r = btree_level_count(root->right);
	return (ft_max(l, r));
}
