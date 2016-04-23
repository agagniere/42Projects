/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hm_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:52:07 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/23 18:05:32 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*hm_memcpy(void *dst, const void *src, size_t len)
{
	void const *const save = dst;

	while (len-- > 0)
		*(char *)(dst++) = *(char *)(src++);
	return (save);
}

void	*hm_memdup(void *src, size_t len)
{
	void	*dst;
	void	*tmp;

	if ((dst = malloc(len)))
	{
		tmp = dst;
		while (len-- > 0)
			*(char *)(tmp++) = *(char *)(src++);
	}
	return (dst);
}
