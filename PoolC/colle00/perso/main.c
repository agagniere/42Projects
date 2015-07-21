/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 13:52:52 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/12 15:59:16 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	colle(int x, int y);

int		is_numeric(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	ans;

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

int		main(int ac, char **av)
{
	int	x;
	int	y;

	if (ac == 4)
	{
		x = ft_atoi(av[2]);
		y = ft_atoi(av[3]);
		if (av[1][0] == '0')
			colle(x, y);
		//if (av[1][0] == '1')
		//colle1(x, y);
	}
	else
		engine(5,4, "/-\\| +o_O");
}
