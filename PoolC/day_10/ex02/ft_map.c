/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 11:45:08 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/21 12:36:15 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int					*ans;

	if (!(ans = (int*)malloc(sizeof(int) * length)))
		return (NULL);
	while (length-- > 0)
		ans[length] = f(tab[length]);
	return (ans);
}
