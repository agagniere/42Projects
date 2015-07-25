/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 15:47:36 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/23 17:01:35 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"
#include <stdio.h>

void	db_printint(char *name, int value)
{
	printf("La variable %s %s %s a pour valeur :\t%s %i %s\n", BOLD, name, END, BOLD, value, END);
}
