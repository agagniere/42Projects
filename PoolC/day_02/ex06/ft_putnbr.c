/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 22:39:23 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/10 09:59:04 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	my_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		++str;
	}
}

int		mpc(char c)
{
	ft_putchar(c + 48);
	return (0);
}

int		mpn(int n)
{
	n = (n < 0 ? mpc(-3) - n : n);
	return (n < 10 ? mpc(n) : mpn(n / 10) + mpc(n % 10));
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		my_putstr("-2147483648");
	else
		mpn(n);
}
