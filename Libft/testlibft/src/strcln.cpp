/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcln.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:44:18 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/29 12:10:02 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

char	*strcln(char const *str)
{
	char	*ans;
	int		len;
	int		offset;

	if (str == NULL)
		return ("NULL");
	len = -1;
	offset = 0;
	while (str[++len] != '\0')
		if (iscntrl(str[len]))
			offset++;
	ans = (char *)malloc(len + offset + 1);
	ans[len + offset] = '\0';
	len = -1;
	offset = 0;
	while (str[++len] != '\0')
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
		default :
			ans[len + offset] = str[len];
		}
	return (ans);
}
