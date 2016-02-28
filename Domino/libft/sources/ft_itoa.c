/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:52:27 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/30 19:20:58 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tenpow(unsigned int nb)
{
	if (nb > 0)
		return (10 * ft_tenpow(nb - 1));
	return (1);
}

static int	ft_nb_c(int n)
{
	int		count;

	count = 1;
	if (n > 999999999)
		return (10);
	if (n < -999999999)
		return (11);
	while (n / ft_tenpow(count) != 0)
		count++;
	if (n < 0)
		count++;
	return (count);
}

static int	easy(char **ret)
{
	(*ret)[0] = '-';
	(*ret)[1] = '2';
	(*ret)[2] = '1';
	(*ret)[3] = '4';
	(*ret)[4] = '7';
	(*ret)[5] = '4';
	(*ret)[6] = '8';
	(*ret)[7] = '3';
	(*ret)[8] = '6';
	(*ret)[9] = '4';
	(*ret)[10] = '8';
	(*ret)[11] = 0;
	return (1);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		neg;

	neg = n < 0 ? 1 : 0;
	ret = (char*)malloc(ft_nb_c(n) + 1);
	if (n == -2147483648 && easy(&ret))
		return (ret);
	i = ft_nb_c(n);
	n = neg == 1 ? -n : n;
	if (!ret)
		return (NULL);
	ret[i] = '\0';
	while (i-- + 1 - neg)
	{
		ret[i] = n % 10 + '0';
		n = n / 10;
	}
	if (neg == 1)
		ret[0] = '-';
	return (ret);
}
