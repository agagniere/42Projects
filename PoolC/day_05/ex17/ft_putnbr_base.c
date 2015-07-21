/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 18:22:45 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/15 20:34:14 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		mpc(char c)
{
	ft_putchar(c);
	return (0);
}

int		mpn(int n, int b, char *base)
{
	n = (n < 0 ? mpc('-') - n : n);
	return (n < b ? mpc(base[n]) : mpn(n / b, b, base) + mpc(base[n % b]));
}

int		len_ok(char *base)
{
	char	*ans;
	char	*n;

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

void	ft_putnbr_base(int nbr, char *base)
{
	int b;

	b = len_ok(base);
	if (b > 1)
		mpn(nbr, b, base);
}
