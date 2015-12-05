/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:21:32 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/05 13:41:47 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dyna	*ft_dyna_new(size_t chunck_size)
{
	t_dyna	*ans;

	ans = (t_dyna *)malloc(sizeof(t_dyna));
	ans->chunck_size = chunck_size;
	return(ft_dyna_datainit(ans) ? NULL : ans);
}
