/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:37:29 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/28 13:05:04 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define ABS(v) ((v) < 0 ? -(v) : (v))

void	aux_dix(int n, char *ans, int *p)
{
	if (n < -9 || 9 < n)
		aux_dix(n / 10, ans, p);
	ans[(*p)++] = '0' + ABS(n % 10);
}

void	aux(unsigned int n, unsigned int b, char *ans, int *p)
{
	char const	base[] = "0123456789ABCDEF";

	if (n >= b)
		aux(n / b, b, ans, p);
	ans[(*p)++] = base[n % b];
}

char	*ft_itoa_base(int value, int base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base
		|| !(ans = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	if (base == 10 && value < 0)
		ans[p++] = '-';
	if (base == 10)
		aux_dix(value, ans, &p);
	else
		aux((unsigned int)value, (unsigned int)base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
