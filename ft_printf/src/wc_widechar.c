/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_widechar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 18:59:18 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/27 19:31:42 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	wc_strlen(const wchar_t *str)
{
	const wchar_t	*ptr = str;

	while (*ptr != '\0')
		ptr++;
	return (ptr - str);
}
