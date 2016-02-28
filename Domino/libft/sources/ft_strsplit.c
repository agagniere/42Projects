/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:21:28 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/21 12:21:36 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	comptemots(const char *str, char c)
{
	int		r;
	int		i;

	r = 0;
	i = 0;
	if (str[i] == c)
		while (str[i] != '\0' && str[i] == c)
			i++;
	while (str[i] != '\0')
	{
		if (str[i + 1] == '\0' && str[i] != c)
			r++;
		if (str[i] == c)
		{
			r++;
			while (str[i + 1] == c)
			{
				i++;
			}
		}
		i++;
	}
	return (r);
}

static int	longueurdumot(const char *str, int i, char c)
{
	int		ret;

	ret = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		ret++;
	}
	return (ret);
}

char		**ft_strsplit(const char *str, char c)
{
	int		i;
	int		m;
	int		l;
	char	**res;

	if (!(res = malloc(comptemots(str, c) * ft_strlen(str))))
		return (NULL);
	i = 0;
	m = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			l = 0;
			if (!(res[m] = malloc(longueurdumot(str, i, c) + 1)))
				return (NULL);
			while (str[i] != c && str[i] != '\0')
				res[m][l++] = str[i++];
			res[m++][l] = '\0';
		}
	}
	res[m] = NULL;
	return (res);
}
