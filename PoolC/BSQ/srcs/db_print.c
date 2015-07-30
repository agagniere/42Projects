/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 12:47:44 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/29 13:24:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"
#include <stdio.h>

#define BOLD "\033[1;33m"
#define END "\033[0;0m"

void	db_print_tint(char *name, t_int var)
{
	printf("La variable %s%s%s a pour valeur : %s%u%s\n",
		BOLD, name, END, BOLD, var, END);
}

void	db_print_int(char *name, int var)
{
	printf("La variable %s %s %s a pour valeur : %s %i %s \n",
		BOLD, name, END, BOLD, var, END);
}

void	db_print_str(char *name, char *var)
{
	printf("La variable %s%s%s a pour valeur : %s\"%s\"%s\n",
		BOLD, name, END, BOLD, var, END);
}

void	db_print_char(char *name, char var)
{
	printf("La variable %s%s%s a pour valeur : %s'%c'%s (%i)\n",
		BOLD, name, END, BOLD, var, END, var);
}
