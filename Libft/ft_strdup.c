/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:06:48 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/24 18:59:35 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char const	*ptr = s1;
	char		*ans;

	while (ptr[-1] != '\0')
		++ptr;
	ans = (char *)malloc(sizeof(char) * (ptr - s1));
	ptr = s1;
	while (*ptr != '\0')
	{
		ans[ptr - s1] = *ptr;
		ptr++;
	}
	ans[ptr - s1] = '\0';
	return (ans);
}
