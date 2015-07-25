/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 14:55:52 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/22 18:02:37 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_list_str(t_list *begin_list)
{
	t_list *cpy;

	cpy = begin_list;
	printf("[| ");
	while (cpy)
	{
		printf("%s", (char *)cpy->data);
		cpy = cpy->next;
		if (cpy)
			printf(" ; ");
	}
	printf(" |]\n");
}
