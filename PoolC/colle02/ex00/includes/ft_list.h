/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 11:19:12 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/26 21:01:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

t_list				*ft_create_elem(void *data);
t_list				*ft_create_elem_sp(char *data);
void				ft_list_clear(t_list **begin_list);
void				ft_list_push_back(t_list **begin_list, void *data);
void				ft_list_push_back_once(t_list **begin_list, void *data);
void				ft_list_push_front(t_list **begin_list, void *data);
void				ft_list_push_front_sp(t_list **begin_list, char *data);
int					ft_list_size(t_list *begin_list);
t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);
t_list				*ft_list_last(t_list *begin_list);
void				*ft_list_merge(t_list *begin_list);
void				ft_list_reverse(t_list **begin_list);

#endif
