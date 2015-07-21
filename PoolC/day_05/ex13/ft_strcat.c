/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 22:46:24 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/15 23:07:19 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*cpy;
	char	*cs;

	cpy = dest;
	while (*cpy)
		cpy++;
	cs = src;
	while (*cs)
		*cpy++ = *cs++;
	*cpy = 0;
	return (dest);
}
