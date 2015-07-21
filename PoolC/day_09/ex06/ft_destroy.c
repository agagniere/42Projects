/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 07:05:52 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/17 07:05:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ultimator.h"
#include <stdlib.h>

void	ft_destroy(char ***factory)
{
	int a;
	int b;

	a = -1;
	while (factory[++a])
	{
		b = -1;
		while (factory[++b])
			free(factory[a][b]);
		free(factory[a]);
	}
	free(factory);
}
