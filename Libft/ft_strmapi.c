/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:06:48 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/29 14:38:18 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(const char *s1, char (*f)(unsigned int, char))
{
	char const	*ptr;
	char		*ans;
	int			i;

	ptr = s1;
	while (*ptr != '\0')
		++ptr;
	if (!(ans = (char *)malloc(sizeof(char) * (ptr - s1 + 1))))
		return (NULL);
	ptr = s1;
	i = 0;
	while (*ptr != '\0')
		ans[i++] = f(i, *ptr);
	ans[i] = '\0';
	return (ans);
}
