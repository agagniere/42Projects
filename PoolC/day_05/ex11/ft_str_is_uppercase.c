/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 16:03:52 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/15 16:04:38 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_uppercase(char *str)
{
	if (!*str)
		return (1);
	if (*str >= 'A' && *str <= 'Z')
		return (ft_str_is_uppercase(str + sizeof(char)));
	return (0);
}
