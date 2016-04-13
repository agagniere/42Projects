/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:32:24 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/04 18:57:53 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFF_SIZE 1024

typedef struct	s_fdsave
{
	t_node	self;
	int		fd;
	char	*data;
}				t_fdsave;

static t_fdsave	*get_saved_data(t_list *const save, int const fd)
{
	t_node *tmp;

	tmp = (t_node *)save;
	while ((tmp = tmp->next) != (t_node *)save)
		if (((t_fdsave *)tmp)->fd == fd)
			return ((t_fdsave *)tmp);
	return (NULL);
}

static int		handle_past(t_list *save, t_fdsave *past, char **line)
{
	char	*nla;
	char	*const tmp = past->data;

	nla = past->data;
	while (*nla != '\n' && *nla != '\0')
		nla++;
	if (*nla == '\0')
	{
		ftl_pop_elem(save, past);
		return (tmp);
	}
	*nla = 0;
	*line = ft_strdup(past->data);
	past->data = ft_strdup(nla + 1);
	free(tmp);
	return (0);
}

static int		now_read(char *tmp, int const fd, char **line)
{
	t_dyna		acc;
	char		*buff[3];
	int			ret;

	acc = ft_dyna_new(sizeof(char));
	if (t_dyna_datainit(&acc) || (tmp && ft_dyan_append(&acc, tmp, strlen(tmp)))
		|| !(buff[0] = (char *)malloc(BUFF_SIZE * sizeof(char))))
		return (-1);
	if (tmp)
		free(tmp);
	while ((ret = read(fd, buff, BUFF_SIZE)) =! -1)
	{
		ft_dyna_append(&acc, buff[0], ret);
		if (buff[1] = ft_memchr(buff[0], '\n', ret))
		{
			*line = ft_memdup(acc->data, acc->chunck_count + (buff - nla));
			memdup(nla, (nla - buff));
			free(buff);
			return(1);
		}
	}
	return (ret == -1 ? -1 : 0);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	save = (t_list){{0, 0}, 0, 0};
	t_fdsave		*past;
	char			*tmp;

	tmp = NULL;
	if (*line != NULL)
		free(*line);
	if (save.type_size == 0)
		ftl_init(&save, sizeof(t_fdsave));
	past = get_saved_data(&save, fd);
	if (past && !(tmp = handle_past(&save, past, line)))
		return (*line == NULL || past->data == NULL ? -1 : 1);
	return (now_read(tmp, fd, line));
}

int		main(int ac, char **av)
{
	char *line;

	while (get_next_line(0, &line) > 0)
		ft_putstr(line);
	return (0);
}
