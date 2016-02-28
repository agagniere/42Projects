/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:10:29 by tbeauman          #+#    #+#             */
/*   Updated: 2015/11/26 13:52:49 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	if (s2 == NULL || ft_strcmp(s2, "") == 0)
		return ((char*)s1);
	if (ft_strlen(s1) < ft_strlen(s2))
		return (NULL);
	while (ft_strncmp(s1, s2, ft_strlen(s2)) != 0 && *s1)
		s1++;
	return (*s1 ? (char*)s1 : NULL);
}
