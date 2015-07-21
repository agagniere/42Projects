/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 14:33:57 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/12 15:57:56 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_char(int li_co[2], int x, int y, char *brush)
{
	if (li_co == {0,0})
		ft_putchar('a');
}

void	engine(int x, int y, char *brush)
{
	int li_co[2];

	li_co[0] = -1;
	while (++li_co[0] < y)
	{
		li_co[1] = -1;
		while (++li_co[1] < x)
			print_char(li_co, x - 1, y - 1, brush);
		ft_putchar('\n');
	}
}
