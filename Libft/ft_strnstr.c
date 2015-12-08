/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:10:16 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/08 19:50:55 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char const	*save1;
	char const	*save;
	char const	*save2;
	size_t		len_s2;

	save2 = s2;
	save = s1;
	len_s2 = strlen(s2);
	if ((*s1 == 0 && *s2 == 0) || n == 0)
		return ((char *)s1);
	while (*s1 != '\0' && (size_t)(s1 - save) < n && n - (s1 - save) >= len_s2)
	{
		save1 = s1;
		while (*s2 != '\0' && *s1 == *s2)
		{
			++s1;
			++s2;
		}
		if (*s2 == '\0')
			return ((char *)save1);
		s1 = save1 + 1;
		s2 = save2;
	}
	return (NULL);
}
