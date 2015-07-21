/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 23:28:42 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/15 23:40:45 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int k;

	k = 0;
	while (src[k] && k < size)
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = 0;
	return (k);
}
