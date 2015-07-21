/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 08:54:35 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/10 11:57:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_alphabet(void);
void	ft_print_reverse_alphabet(void);
void	ft_print_numbers(void);
void	ft_is_negative(int n);
void	ft_print_comb(void);
void	ft_print_comb2(void);
void	ft_putnbr(int n);
void	ft_print_combn(int n);

void	ft_putstr(char *str);

int		main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	ft_putstr("Exo 00 :\t");
	ft_print_alphabet();
	ft_putstr("\nExo 01 :\t");
	ft_print_reverse_alphabet();
	ft_putstr("\nExo 02 :\t");
	ft_print_numbers();
	ft_putstr("\nExo 03 :\n\t161 :\t");
	ft_is_negative(161);
	ft_putstr("\n\t-273 :\t");
	ft_is_negative(-273);
	ft_putstr("\n\t0 :\t");
	ft_is_negative(0);
	if (av[1][0] == '4')
	{
		ft_putstr("\nExo 04 :\t");
		ft_print_comb();
	}
	if (av[1][0] == '5')
	{
		ft_putstr("\nExo 05 :\t");
		ft_print_comb2();
	}
	if (av[1][0] == '6')
	{
		ft_putstr("\nExo 06 :\n\t42 :\t");
		ft_putnbr(42);
		ft_putstr("\n\t-42 :\t");
		ft_putnbr(-42);
		ft_putstr("\n\t0 :\t");
		ft_putnbr(0);
		ft_putstr("\n\t2147483647 :\t");
		ft_putnbr(2147483647);
	}
	if (ac > 2 && av[1][0] == '7')
	{
		ft_putstr("\nExo 07 :\t");
		ft_print_combn((int)av[2][0]);
	}
	return (0);
}
