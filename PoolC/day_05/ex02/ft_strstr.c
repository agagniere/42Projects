/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 12:45:45 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/15 18:13:55 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*ans;
	char	*tmp;
	char	*aim;

	if (!*to_find)
		return (str);
	tmp = str;
	while (*tmp)
	{
		ans = tmp;
		aim = to_find;
		while (*tmp && *aim && *tmp == *aim)
		{
			++tmp;
			++aim;
		}
		if (!*aim)
			return (ans);
		tmp = ans + 1;
	}
	return (0);
}
