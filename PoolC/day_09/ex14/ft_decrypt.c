/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 12:54:21 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/17 14:01:43 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_perso.h"
#include <stdlib.h>

char		*ft_cut_sp(int s[2], char *str, int cp)
{
	char	*rep;
	int		b;

	rep = (char *)malloc(sizeof(char) * cp - s[1]);
	b = -1;
	while (s[1]++ < cp - 1)
		rep[++b] = str[s[1]];
	rep[b] = 0;
	return (rep);
}

int			ft_atoi_sp(char *str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ')
		str++;
	if (*str == '-')
		sign = -sign;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (sign == -1)
		result = -result;
	return (result);
}

t_perso		**ft_decrypt(char *str)
{
	t_perso		**rep;
	int			all[4];

	all[3] = -1;
	all[2] = 0;
	while (str[++all[3]])
		all[2] += (str[all[3]] == '|' ? 1 : 0);
	if (!(rep = (t_perso **)malloc(sizeof(t_perso *) * all[2])))
		return (NULL);
	all[3] = -1;
	all[2] = 0;
	all[0] = 0;
	all[1] = 0;
	while (str[all[3]++] || all[3] == 0)
	{
		all[1] = (str[all[3]] == '|' ? all[3] : all[1]);
		if (str[all[3]] == ';' || str[all[3]] == 0)
		{
			rep[all[2]]->age = ft_atoi_sp(str + all[3]);
			rep[all[2]]->name = ft_cut_sp(all, str, all[3]);
			all[0] = all[3];
			++all[1];
		}
	}
	return (rep);
}
