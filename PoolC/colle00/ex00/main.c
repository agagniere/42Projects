/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 11:01:20 by hkaddour          #+#    #+#             */
/*   Updated: 2015/07/15 13:10:25 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	colle(int x, int y);
void	print_char01(int ligne, int colonne, int x, int y);
void	print_char02(int ligne, int colonne, int x, int y);
void	print_char03(int ligne, int colonne, int x, int y);
void	print_char04(int ligne, int colonne, int x, int y);

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
	return (ans * sign);
}

void	colle_engine(int x, int y, char n)
{
	int ligne;
	int colonne;

	ligne = 0;
	while (ligne < y)
	{
		colonne = 0;
		while (colonne < x)
		{
			if (n == 1)
				print_char01(ligne, colonne, x, y);
			if (n == 2)
				print_char02(ligne, colonne, x, y);
			if (n == 3)
				print_char03(ligne, colonne, x, y);
			if (n == 4)
				print_char04(ligne, colonne, x, y);
			colonne++;
		}
		if (x > 0)
			ft_putchar('\n');
		ligne++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		colle(ft_atoi(av[1]), ft_atoi(av[2]));
	if (ac == 4)
	{
		if (av[1][0] == '0')
			colle(ft_atoi(av[2]), ft_atoi(av[3]));
		else
			colle_engine(ft_atoi(av[2]), ft_atoi(av[3]), av[1][0] - 48);
	}
	return (0);
}
