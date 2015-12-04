/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_trim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:17:19 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/04 18:24:43 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_dyna_trim(t_dyna *td)
{
	void	*new_data;

	if (!(new_data = malloc(td->chunk_size * td_chunck)))
		return (1);
	ft_mem
}
