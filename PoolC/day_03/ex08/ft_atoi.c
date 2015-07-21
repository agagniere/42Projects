/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 12:36:10 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/11 13:20:42 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_numeric(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int i;
	int sign;
	int ans;

	i = -1;
	while (str[++i] == ' ')
		;
	sign = (str[i] == '-' ? -1 : 1);
	i += (str[i] == '-' || str[i] == '+' ? 1 : 0);
	ans = 0;
	while (is_numeric(str[i]))
		ans = 10 * ans + str[i++] - 48;
	return (ans);
}
