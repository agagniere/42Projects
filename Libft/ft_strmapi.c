/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:06:48 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/07 17:25:54 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(const char *s1, char (*f)(unsigned int, char))
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
	{
		ans[i] = f(i, *ptr++);
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
