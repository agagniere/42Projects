/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 10:44:53 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/27 10:44:54 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

typedef struct	s_coord
{
	int x;
	int y;
}				t_coord;
typedef char	(*t_fun)(t_coord *point, t_coord *total);
typedef struct	s_form
{
	char	*name;
	t_fun	get_char_at;
}				t_form;

char			colle_00_0(t_coord *point, t_coord *total);
char			colle_00_1(t_coord *point, t_coord *total);
char			colle_00_2(t_coord *point, t_coord *total);
char			colle_00_3(t_coord *point, t_coord *total);
char			colle_00_4(t_coord *point, t_coord *total);
char			rectangle(t_coord *point, t_coord *total);
char			triangle_a(t_coord *point, t_coord *total);
char			triangle_b(t_coord *point, t_coord *total);
char			triangle_c(t_coord *point, t_coord *total);
char			triangle_d(t_coord *point, t_coord *total);

#endif
