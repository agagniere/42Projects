/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 23:10:32 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/15 23:13:53 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	char	*cpy;
	char	*cs;
	int		i;

	cpy = dest;
	while (*cpy)
		cpy++;
	cs = src;
	i = 0;
	while (*cs && ++i < nb)
		*cpy++ = *cs++;
	*cpy = 0;
	return (dest);
}
