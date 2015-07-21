/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 16:40:15 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/14 16:55:46 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
{
	if (!*str)
		return (1);
	if (*str >= '0' && *str <= '9')
		return (ft_str_is_numeric(str + sizeof(char)));
	return (0);
}
