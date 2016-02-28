/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:08:35 by tbeauman          #+#    #+#             */
/*   Updated: 2015/11/25 14:09:52 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n > ft_strlen(s1))
		return (ft_strstr(s1, s2));
	while (ft_strncmp(s1, s2, ft_strlen(s2)) != 0 && *s1 &&
			i + ft_strlen(s2) - 1 < n)
	{
		i++;
		s1++;
	}
	if (i + ft_strlen(s2) - 1 == n)
		return (NULL);
	return (*s1 ? (char*)s1 : NULL);
}
