/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:48:00 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/28 14:26:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ans;
	int		i;

	i = 0;
	if (!(ans = (char *)malloc(sizeof(char)
		* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1 != '\0')
		ans[i++] = *s1++;
	while (*s2 != '\0')
		ans[i++] = *s2++;
	ans[i] = '\0';
	return (ans);
}
