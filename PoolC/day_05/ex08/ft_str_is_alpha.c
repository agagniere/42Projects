/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 16:28:44 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/14 16:36:05 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	if (!*str)
		return (1);
	if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
		return (ft_str_is_alpha(str + sizeof(char)));
	else
		return (0);
}
