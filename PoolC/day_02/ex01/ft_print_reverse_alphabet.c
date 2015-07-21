/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 15:25:08 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/09 15:30:20 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void ft_print_reverse_alphabet(void)
{
	char c;

	c = 'z' + 1;
	while (--c >= 'a')
		ft_putchar(c);
}
