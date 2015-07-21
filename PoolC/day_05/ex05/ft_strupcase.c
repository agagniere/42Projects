/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 15:51:01 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/14 16:15:15 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_lower_case(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	int k;

	k = -1;
	while (str[++k])
		if (is_lower_case(str[k]))
			str[k] -= 32;
	return (str);
}
