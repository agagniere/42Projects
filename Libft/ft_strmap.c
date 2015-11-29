/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:06:48 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/29 14:31:21 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(const char *s1, char (*f)(char))
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
		ans[ptr - s1] = f(*ptr);
		ptr++;
	}
	ans[ptr - s1] = '\0';
	return (ans);
}
