/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 18:15:40 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/15 18:16:03 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_upper_case(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int k;

	k = -1;
	while (str[++k])
		if (is_upper_case(str[k]))
			str[k] += 32;
	return (str);
}
