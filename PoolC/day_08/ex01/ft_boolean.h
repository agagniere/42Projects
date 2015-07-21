/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 10:07:13 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/21 18:38:26 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define EVEN(x) !(x % 2)
# define SUCCESS 0
# define EVEN_MSG "I have a pair number of arguments"
# define ODD_MSG "I have an impair number of arguments"

typedef int		t_bool;

#endif
