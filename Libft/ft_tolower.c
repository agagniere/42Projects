/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:26:01 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/27 12:17:24 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	//if ('A' <= c && c <= 'Z')
	if (ft_isalpha(c))
		return (c | ('A' ^ 'a'));
	else
		return (c);
}
