/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:36:58 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/21 10:43:33 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = (char*)malloc(size);
	if (!ret)
		return (NULL);
	while (i < size)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}
