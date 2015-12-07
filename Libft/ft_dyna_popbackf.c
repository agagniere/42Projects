/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_popback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 20:08:29 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/07 21:42:23 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_dyna_popback(t_dyna *td, void (*del)(void *))
{
	if (td->chunck_count > 0)
	{
		td->chunck_count--;
		del(td->data + td->chunck_count * td->chunck_size);
	}
}
