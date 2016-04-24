/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 13:16:19 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/24 22:47:24 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

#include <stdio.h> //<--

static void		hr_find(char *str)
{

}

static int		hr_act(t_reader_data *w, t_hmap *data, char *ptr)
{
	char	*str;

	if (ptr == w->start)
	{
		w->key_val = 2;
		return (0);
	}
	if (!(str = hm_memdup(w->start, ptr - w->start)))
		return (1);
	str[ptr - w->start - 1] = '\0';
	printf("I read %s as a %s\n", str, w->key_val ? "value" : "key");
	if (w->key_val == 0)
		w->elem.key = str;
	else if (w->key_val == 1)
	{
		w->elem.value = str;
		hm_add(data, (t_hm_node *)&(w->elem));
	}
	else
		hr_find(str);
	if (w->key_val < 2)
		w->key_val = !w->key_val;
	w->start = ptr + 1;
	return (0);
}

static int				hr_read(t_hmap *data)
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
		while (ptr < w->end && *ptr != '\n')
			ptr++;
		if (ptr == w->end)
		{
			hm_memmove(w->start, w->buffer, ptr - w->start);
			w->offset = ptr - w->start;
		}
		else if (hr_act(w, data, ptr))
			return (1);
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
