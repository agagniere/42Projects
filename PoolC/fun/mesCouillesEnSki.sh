# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mesCouillesEnSki.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/16 18:41:30 by angagnie          #+#    #+#              #
#    Updated: 2015/07/16 18:50:38 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

mkdir ex00 ex01 ex02 ex03 ex04 ex05 ex06 ex07 ex08 ex09 ex10 ex11

# ---=== Ex00 ===---
echo "/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: $USER <$USER@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 18:09:52 by $USER          #+#    #+#             */
/*   Updated: 2015/07/16 18:13:00 by $USER         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void\tft_generic(void)
{
\twrite(1, \"Tu tu tu tu ; Tu tu tu tu\\\n\", 26);
}" > ex00/ft_generic.c

# ---=== Ex01 ===---
echo "/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: $USER <$USER@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 18:17:51 by $USER          #+#    #+#             */
/*   Updated: 2015/07/16 18:36:52 by $USER         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int\t\tft_convert(int h)
{
\tif (h == 0 || h == 24 || h == 12)
\t\treturn (12);
\treturn (h % 12);
}

void\tft_takes_place(int hour)
{
\tprintf(\"THE FOLLOWING TAKES PLACE BETWEEN %i.00 %c.M. AND %i.00 %c.M.\\\n\",
\t\tft_convert(hour),
\t\thour < 12 || hour == 24 ? 'A' : 'P',
\t\tft_convert(hour + 1),
\t\thour < 11 || hour > 22 ? 'A' : 'P');
}" > ex01/ft_takes_place.c