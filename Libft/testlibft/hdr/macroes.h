/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macroes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:14:10 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/25 20:46:12 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROES_H
# define MACROES_H

# define SIZE_ARRAY(A) (sizeof((A)) / sizeof(*(A)))
# define STRIDE_ARRAY(A) (sizeof(*(A)))
# define END_ARRAY(A) ((void*)(A) + sizeof((A)))

#define MARK(success) if (success)              \
        printf(GREEN);                          \
    else                                        \
        printf(RED);                            \
    printf(".%s", END)

#endif
