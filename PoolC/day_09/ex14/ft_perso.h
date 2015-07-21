/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agagnier <agagnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/18 05:10:32 by agagnier          #+#    #+#             */
/*   Updated: 2014/07/18 05:39:08 by agagnier         ###   ########.fr       */
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
