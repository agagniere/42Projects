/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 09:36:37 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/11 13:37:05 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen_tmp(char *str)
{
	char *tmp;

	tmp = str;
	while (*tmp)
		tmp++;
	return (tmp - str);
}

char	*ft_strrev(char *str)
{
	char	tmp[ft_strlen_tmp(str) + 1];
	int		len;
	int		n;

	len = ft_strlen_tmp(str) + 1;
	n = -1;
	while (str[++n] != 0)
		tmp[len - 2 - n] = str[n];
	tmp[len - 1] = 0;
	n = -1;
	while (tmp[++n] != 0)
		str[n] = tmp[n];
	return (str);
}
