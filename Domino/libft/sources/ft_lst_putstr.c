/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:46:15 by tbeauman          #+#    #+#             */
/*   Updated: 2015/11/27 18:37:08 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_putstr(t_list *lst)
{
	while (lst)
	{
		ft_putstr(lst->content);
		ft_putchar('\n');
		lst = lst->next;
	}
}
