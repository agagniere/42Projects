/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 01:09:48 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/30 03:03:05 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

void	destroy_work(t_work *work)
{
	free(work->cur_line);
	free(work->max);
	free(work->map);
	free(work);
}
