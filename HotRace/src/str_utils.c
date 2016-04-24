/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 22:59:58 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/24 23:03:15 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	hr_strlen(char const *str)
{
	char const *const save = str;

	while (*str != '\0')
		str++;
	return (str - save);
}
