/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gooo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 13:21:06 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/26 23:18:38 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"
#include "formtab.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar('0' + n % 10);
}

void	print_result(char **names, t_coord **dim, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (i > 0)
			ft_putstr(" || ");
		ft_putchar('[');
		ft_putstr(names[i]);
		ft_putstr("] [");
		ft_putnbr(dim[i]->x);
		ft_putstr("] [");
		ft_putnbr(dim[i]->y);
		ft_putstr("]");
	}
	ft_putchar('\n');
}

void	gooo(char **tab, t_coord *max)
{
	int		i;
	int		j;
	t_bool	f;
	char	**stock_name;
	t_coord **stock_coord;

	stock_name = (char **)malloc(sizeof(char *) * 100);
	stock_coord = (t_coord **)malloc(sizeof(t_coord *) * 100);
	i = 0;
	j = 0;
	while (g_formtab[i].get_char_at)
	{
		f = check_form(g_formtab[i].get_char_at, tab, max);
		if (f == TRUE)
		{
			stock_name[j] = ft_strdup(g_formtab[i].name);
			stock_coord[j++] = new_coordinate(max->x, max->y);
		}
		i++;
	}
	print_result(stock_name, stock_coord, j);
}
