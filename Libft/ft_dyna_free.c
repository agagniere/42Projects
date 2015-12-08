/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:59:29 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/08 11:03:25 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_dyna_free(t_dyna **tda)
{
	ft_dyna_dataclear(*tda);
	free(*tda);
	*tda = NULL;
}
