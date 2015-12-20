/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 18:24:51 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/20 18:25:31 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int      max_index(int *b, int len)
{
	int ans;
	int i;

	i = 0;
	ans = 0;
	while (++i < len)
		if (b[i] > b[ans])
			ans = i;
	return (ans);
}

int      min_index(int *b, int len)
{
	int ans;
	int i;

	i = 0;
	ans = 0;
	while (++i < len)
		if (b[i] < b[ans])
			ans = i;
	return (ans);
}
