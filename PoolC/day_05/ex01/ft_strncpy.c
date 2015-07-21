/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 12:29:02 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/15 18:01:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int k;

	k = -1;
	while (src[++k] && k < n)
		dest[k] = src[k];
	while (k < n)
		dest[k++] = 0;
	return (dest);
}
