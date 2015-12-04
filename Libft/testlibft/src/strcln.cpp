/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcln.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:44:18 by angagnie          #+#    #+#             */
//   Updated: 2015/12/04 11:04:36 by angagnie         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

char	*strcln(char const *str, size_t size)
{
	char	*ans;
	size_t	len;
	int		offset;
	int		forced;

	if (str == NULL)
		return (strdup("[NULL]"));
	forced = size;
	if (size == 0)
		size = strlen(str);
	len = 0;
	offset = 0;
	while (len < size)
		if (iscntrl(str[len++]) || forced)
			offset++;
	ans = (char *)malloc(len + offset + 1);
	ans[len + offset] = '\0';
	len = 0;
	offset = 0;
	while (len < size)
	{
		switch (str[len])
		{
		case '\v' :
			ans[len + offset++] = (char)'\\';
			ans[len + offset] = (char)'v';
			break;
		case '\f' :
			ans[len + offset++] = (char)'\\';
			ans[len + offset] = (char)'f';
			break;
		case '\t' :
			ans[len + offset++] = (char)'\\';
			ans[len + offset] = (char)'t';
			break;
		case '\r' :
			ans[len + offset++] = (char)'\\';
			ans[len + offset] = (char)'r';
			break;
		case '\n' :
			ans[len + offset++] = (char)'\\';
			ans[len + offset] = (char)'n';
			break;
		case '\a' :
			ans[len + offset++] = (char)'\\';
			ans[len + offset] = (char)'a';
			break;
		case '\b' :
			ans[len + offset++] = (char)'\\';
			ans[len + offset] = (char)'b';
			break;
		case '\0' :
			ans[len + offset++] = (char)'\\';
			ans[len + offset] = (char)'0';
			break;
		default :
			ans[len + offset++] = str[len];
			ans[len + offset] = ' ';
		}
		len++;
	}
	return (ans);
}
