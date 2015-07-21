/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 22:26:44 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/15 23:02:52 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alphanumeric(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	if ('A' <= c && c <= 'Z')
		return (1);
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		was_an;
	char	*cpy;

	was_an = 0;
	cpy = str - 1;
	while (*(++cpy))
	{
		if (!was_an && *cpy >= 'a' && *cpy <= 'z')
			*cpy -= 32;
		if (was_an && *cpy >= 'A' && *cpy <= 'Z')
			*cpy += 32;
		if (is_alphanumeric(*cpy))
			was_an = 1;
		else
			was_an = 0;
	}
	return (str);
}
