/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 15:38:57 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/09 21:31:28 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//void ft_putchar(char c);
int		ft_len(char *str);

void	ft_putstr(char *str)
{
	write(1, str, ft_len(str));
}
