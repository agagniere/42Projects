/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_widechar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 18:59:18 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/30 14:08:14 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	wc_strlen(const wchar_t *str)
{
	const wchar_t	*ptr = str;

	while (*ptr != L'\0')
		ptr++;
	return (ptr - str);
}
