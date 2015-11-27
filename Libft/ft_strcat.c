/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:48:00 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/27 16:16:05 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strcat(char *s1, const char *s2)
{
	char *const		ans =
		(char *)malloc(sizeof(char) * (ft_strlen(l1) + ft_strlen(l2) + 1));
	int				i;

	i = 0;
	while (*s1 != '\0')
		ans[i++] = *s1++;
	while (*s2 != '\0')
		ans[i++] = *s2++;
	ans[i] = '\0';
}
