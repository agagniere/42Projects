/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ministr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:19:08 by tbeauman          #+#    #+#             */
/*   Updated: 2015/11/27 17:27:00 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ministr(char *s)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char*)malloc(ft_strlen(s) + 1);
	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90)
			ret[i] = s[i] + 32;
		else
			ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
