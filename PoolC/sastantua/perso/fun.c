/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 13:35:28 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/12 17:35:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_charn(char c, int n)
{
	while (n-- > 0)
		ft_putchar(c);
}

void	draw(int line, int total, int *porte, char *brush)
{
	int		spaces;

	spaces = (total - line) / 2;
	print_charn(brush[0], spaces);
	ft_putchar(brush[1]);
	if (porte[0] == 0)
		print_charn(brush[2], line - 2);
	else
	{
		print_charn(brush[2], ((line - porte[1] - 2) / 2));
		if (porte[0] == 2)
		{
			print_charn(brush[3], porte[1] - 2);
			ft_putchar(brush[4]);
			ft_putchar(brush[3]);
		}
		else
			print_charn(brush[3], porte[1]);
		print_charn(brush[2], ((line - 2 - porte[1]) / 2));
	}
	ft_putchar(brush[5]);
	print_charn(brush[0], spaces);
	ft_putchar('\n');
}

int		get_width(int size)
{
	if (size == 1)
		return (5);
	return (get_width(size - 1)  + 2 * (size + 2) + 2 * (size / 2) + 2);
}

void	sastantua(int size, char* brush)
{
	int all[5];
	int portail[2];

	all[1] = 1;
	all[0] = get_width(size) + 2;
	portail[0] = 0;
	portail[1] = size - ((size + 1) % 2);
	while (all[1] <= size)
	{
		all[2] = all[1] + 2;
		all[3] = get_width(all[1]) + 2;
		all[4] = 0;
		while (++all[4] <= all[2])
		{
			if ((all[1] == size)
				&& ((all[2] - all[4]) == portail[1] / 2)
				&& (size > 4))
				portail[0] = 2;
			else if ((all[1] == size) && ((all[2] - all[4]) < portail[1]))
				portail[0] = 1;
			draw(all[3] - 2 * (all[2] - all[4]), all[0], portail, brush);
		}
		++all[1];
	}
}
