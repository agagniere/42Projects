/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 20:12:27 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/07 21:46:44 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size, size_t factor)
{
	void	*ans;

	if (ptr == NULL)
		return (malloc(new_size * factor));
	if (new_size < old_size)
		old_size = new_size;
	ans = malloc(new_size * factor);
	ft_memcpy(ptr, ans, old_size * factor);
	free(ptr);
	return (ans);
}
