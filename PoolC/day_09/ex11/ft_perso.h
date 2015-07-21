/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 07:07:49 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/17 07:07:51 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H

# include <string.h>
# define SAVE_AUSTIN_POWERS 31415
typedef struct	s_perso
{
	char		*name;
	double		life;
	int			age;
	int			profession;
}				t_perso;

#endif
