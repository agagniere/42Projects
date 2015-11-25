/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:26:03 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/25 17:33:47 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ans;

	if (!(ans = malloc(size)))
		return (NULL);
	while (size-- > 0)
		*((unsigned char *)(ans + size)) = 0;
	return (ans);
}
