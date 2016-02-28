/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:54:01 by tbeauman          #+#    #+#             */
/*   Updated: 2015/11/26 18:12:44 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*ret;
	unsigned int		i;

	ret = (char*)malloc(len + 1);
	if (!ret)
		return (NULL);
	i = start;
	while (len--)
	{
		ret[i - start] = s[i];
		i++;
	}
	ret[i - start] = '\0';
	return (ret);
}
