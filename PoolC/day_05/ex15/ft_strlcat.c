/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 23:16:38 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/15 23:40:35 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*cpy;
	char			*cs;
	unsigned int	i;

	i = 0;
	cpy = dest - 1;
	while (*(++cpy))
		i++;
	cs = src;
	while (*cs && ++i < size)
		*cpy++ = *cs++;
	if (i < size)
		*cpy = 0;
	return (i);
}
