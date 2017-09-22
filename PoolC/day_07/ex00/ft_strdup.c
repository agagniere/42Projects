/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 09:03:06 by angagnie          #+#    #+#             */
/*   Updated: 2017/08/09 20:26:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*cpy;
	char	*ans;
	char	*tmp;

	cpy = src;
	while (*cpy++)
		;
	ans = (char *)malloc(sizeof(char) * (cpy - src));
	if (ans == NULL)
		return (NULL);
	cpy = src;
	tmp = ans;
	while (*cpy)
		*(tmp++) = *(cpy++);
	*tmp = 0;
	return (ans);
}
