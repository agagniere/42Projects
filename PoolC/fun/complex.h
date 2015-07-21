/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 23:15:28 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/12 23:33:46 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <assert.h>


typedef		struct
{
	double rep;
	double imp;
	double mod;
	double arg;
}			t_complex;

t_complex	*create_complex_carte(double rep, double imp);
t_complex	*create_complex_polar(double mod, double arg);
void		update_polar(t_complex *c);
void		update_carte(t_complex *c);

#fi
