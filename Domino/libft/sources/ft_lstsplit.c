/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:06:58 by tbeauman          #+#    #+#             */
/*   Updated: 2015/11/27 16:15:26 by tbeauman         ###   ########.fr       */
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

t_list		*ft_lstsplit(char const *s, char c)
{
	char	**tab;
	t_list	*ret;
	int		i;

	tab = ft_strsplit(s, c);
	i = 0;
	ret = NULL;
	while (i < comptemots(s, c))
	{
		ft_lstadd(&ret, ft_lstnew(tab[i], ft_strlen(tab[i])));
		i++;
	}
	return (ret);
}
