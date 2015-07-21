/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 16:04:58 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/15 16:05:20 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	if (!*str)
		return (1);
	if (*str >= 'a' && *str <= 'z')
		return (ft_str_is_lowercase(str + sizeof(char)));
	return (0);
}
