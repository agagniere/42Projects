/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:00:30 by tbeauman          #+#    #+#             */
/*   Updated: 2015/11/24 18:51:25 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		l;
	int		i;
	char	*a;

	l = 0;
	i = 0;
	while (*s)
	{
		l++;
		s++;
	}
	a = (char*)s;
	while (i <= l)
	{
		if (*s == (char)c)
			return ((char*)s);
		s -= 1;
		i++;
	}
	if ((char)c == '\0')
		return ((char*)a);
	else
		return (NULL);
}
