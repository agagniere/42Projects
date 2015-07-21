/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 09:26:28 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/16 15:16:42 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*ans;
	int	i;

	if (max <= min)
		return (0);
	ans = (int *)malloc((max - min) * sizeof(int));
	if (!ans)
		return (0);
	i = -1;
	while (++i < max - min)
		ans[i] = i + min;
	return (ans);
}
