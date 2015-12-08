/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:38:45 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/08 19:52:07 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char const	*p;

	p = s;
	while (*p != '\0')
		p++;
	while (*(const unsigned char)p != c && p >= s)
		p--;
	return (*p == c ? (char *)p : NULL);
}
