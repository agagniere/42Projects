/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_dataclear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:46:25 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/04 17:51:08 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dyna_dataclear(t_dyna t)
{
	free(t->data);
	t->chunck_count = 0;
	t->chunck_max = 0;
}
