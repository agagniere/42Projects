/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 09:03:06 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/16 15:02:08 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*cpy;
	char	*ans;
	char	*tmp;

	cpy = src - 1;
	while (*(++cpy))
		;
	ans = (char *)malloc(sizeof(char) * (cpy - src + 1));
	if (ans == NULL)
		return (NULL);
	cpy = src;
	tmp = ans;
	while (*cpy)
		*(tmp++) = *(cpy++);
	*tmp = 0;
	return (ans);
}
