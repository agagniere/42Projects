/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:06:48 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/29 08:53:45 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char const	*ptr;
	char		*ans;

	ptr = s1;
	while (*ptr != '\0')
		++ptr;
	if (!(ans = (char *)malloc(sizeof(char) * (ptr - s1 + 1))))
		return (NULL);
	ptr = s1;
	while (*ptr != '\0')
	{
		ans[ptr - s1] = *ptr;
		ptr++;
	}
	ans[ptr - s1] = '\0';
	return (ans);
}
