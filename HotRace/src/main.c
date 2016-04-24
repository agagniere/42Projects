/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:16:19 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/24 22:24:09 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#define BUFF_SIZE 2048

static int		act(t_reader_data *w, t_hmap *data)
{
	char	*str;

	if (!(str = ft_memdup(start, ptr - start)))
		return (1);
	str[ptr - start - 1] = '\0';
	if (key_val == 0)
		w->elem.key = str;
	else if (key_val == 1)
	{
		w->elem.value = str;
		hm_add(data, w->elem);
	}
	else
		SEARCH(str);
	if (key_val < 2)
		key_val = !key_val;
	w->start = ptr + 1;
}

int				read(t_hmap *data)
{
	t_reader_data	w[1];
	char			*ptr;

	key_val = 0;
	w->offset = 0;
	while ((w->ret = read(0, buffer + offset, BUFF_SIZE - w->offset)) > 0)
	{
		ptr = w->buffer;
		w->start = ptr;
		w->end = w->buffer + w->ret * sizeof(char);
		while (ptr < w->end && *ptr != '\n')
			ptr++;
		if (ptr == w->end)
		{
			hm_memmove(start, buffer, ptr - start);
			w->offset = ptr - start;
		}
		else if (act(w, data))
			return (1);
	}
}

int				main(void)
{
	t_hmap	data;

	data = NEW_HMAP(sizeof(t_hr_kv), &hr_strequ, &hr_djb2);
	if (read(&data))
		write(1, "Error\n", 6);
	return (0);
}
