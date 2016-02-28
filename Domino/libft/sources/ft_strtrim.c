/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:08:46 by tbeauman          #+#    #+#             */
/*   Updated: 2015/11/26 14:22:32 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspaces(char const *s)
{
	while (*s != '\0')
	{
		if (*s != 32 && *s != '\n' && *s != '\t')
			return (0);
		s++;
	}
	return (1);
}

char		*ft_strtrim(char const *s)
{
	char	*ret;
	int		i;

	if (!s)
		return (NULL);
	ret = (char*)malloc(ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (*s == 32 || *s == '\n' || *s == '\t')
		s++;
	while (*s != '\0' && ft_isspaces(s) == 0)
	{
		ret[i] = *s;
		s++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
