/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:16:14 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/29 20:17:04 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char *save;

	save = dst;
	while (*src != '\0' && n-- > 1)
		*(dst++) = *(src++);
	while (n-- > 0)
		*(dst++) = '\0';
	return (save);
}
