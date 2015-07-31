/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 20:35:59 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/15 21:13:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		len_ok(char *base)
{
	char*ans;
	char*n;

	ans = base - 1;
	while (*(++ans))
	{
		if (*base == '+' || *base == '-' || *base < '!' || *base > '~')
			return (0);
		n = base - 1;
		while (++n < ans)
			if (*n == *ans)
				return (0);
	}
	return (ans - base);
}

int		ft_atoi_base(char *str, char *base)
{
	int b;

	b = len_ok(base);
	
}
