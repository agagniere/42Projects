/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:16:19 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/26 13:00:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

#define HR_PUTSTR(STR) write(1, STR, hr_strlen(STR))

static void		hr_find(char *str, t_hmap *data)
{
	t_hr_kv		tmp;

	tmp.key = str;
	if (hm_get(data, (t_hm_node *)&tmp))
	{
		HR_PUTSTR(str);
		HR_PUTSTR(": Not found.\n");
	}
	else
	{
		HR_PUTSTR(tmp.value);
		write(1, "\n", 1);
	}
}

static int		hr_act(t_reader_data *w, t_hmap *data, char *ptr)
{
	char	*str;

	if (ptr == w->start)
	{
		w->key_val = 2;
		return (0);
	}
	if (!(str = hm_memdup(w->start, ptr - w->start + 1)))
		return (1);
	str[ptr - w->start] = '\0';
	if (w->key_val == 0)
		w->elem.key = str;
	else if (w->key_val == 1)
	{
		w->elem.value = str;
		hm_add(data, (t_hm_node *)&(w->elem));
	}
	else
		hr_find(str, data);
	if (w->key_val < 2)
		w->key_val = !w->key_val;
	return (0);
}

static int		hr_read(t_hmap *data)
{
	t_reader_data	w[1];
	char			*ptr;

	w->key_val = 0;
	w->offset = 0;
	while ((w->ret = read(0, w->buffer + w->offset, BUFF_SIZE - w->offset)) > 0)
	{
		ptr = w->buffer;
		w->start = ptr;
		w->end = w->buffer + (w->ret + w->offset) * sizeof(char);
		while (1)
		{
			while (ptr < w->end && *ptr != '\n')
				ptr++;
			if (ptr == w->end)
			{
				hm_memmove(w->start, w->buffer, ptr - w->start);
				w->offset = ptr - w->start;
				break ;
			}
			if (hr_act(w, data, ptr) || !(w->start = ++ptr))
				return (1);
		}
	}
	return (0);
}

int				main(void)
{
	t_hmap	data;

	data = NEW_HMAP(sizeof(t_hr_kv), &hr_strequ, &hr_djb2);
	if (hr_read(&data))
		write(1, "Error\n", 6);
	return (0);
}
