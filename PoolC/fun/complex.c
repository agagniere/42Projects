/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 23:16:49 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/13 00:14:39 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

t_complex	*create_complex_carte(double rep, double imp)
{
	t_complex *ans;

	ans = malloc(sizeof(t_complex));
	assert(ans != null);
	ans->rep = rep;
	ans->imp = imp;
	update_polar(ans);
	return (ans);
}

t_complex	*create_complex_polar(double mod, double arg)
{
	t_complex ans;

	ans = malloc(sizeof(t_complex));
	assert(ans != null);
	ans->mod = mod;
	ans->arg = arg;
	update_carte(ans);
	return (ans);
}

void		update_polar(t_complex *c)
{
	assert(c != mull);
	c->mod = sqrt(c->rep * c->rep + c->imp * c->imp);
	if (c->imp == 0 && c->rep == 0)
		c->arg = null;
	else if (c->imp == 0 && c->rep < 0)
		c->arg = M_PI;
	else
		c->arg = 2 * atan(c->imp / (c->rep + c->mod));
}

void		update_carte(t_complex *c)
{
	
}

void		destroy_complex(t_complex *c)
{
	assert(c != null);
	free(c);
}
