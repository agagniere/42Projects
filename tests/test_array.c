/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:10:00 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/18 18:12:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int ac, char **av)
{
	t_array		v;
	size_t		n;

	v = NEW_ARRAY(char);
	n = 75;
	while (n-- > 65)
		fta_append(&v, &n, 1);
	fta_append(&v, "\0", 1);
	ft_putstr("Array {\n\tSize\t\t");
	ft_putnbr(v.size);
	ft_putstr("\n\tCapacity\t");
	ft_putnbr(v.max);
	ft_putstr("\n\tType size\t");
	ft_putnbr(v.type_size);
	ft_putstr("\n\tData\t\t");
	ft_putstr((char *)v.data);
	ft_putstr("\n}\n");
	return (0);
}
