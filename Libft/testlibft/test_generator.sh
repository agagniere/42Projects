# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_generator.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 15:25:08 by angagnie          #+#    #+#              #
#    Updated: 2015/11/25 16:21:36 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

file="src/test_"$1".c"
echo "Generating" $file
echo "/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_$1.c\t\t\t\t\t\t\t\t\t\t:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: $USER <$USER@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */" > $file
date "+/*   Created: %Y/%m/%d %H:%M:%S by $USER          #+#    #+#             */" >> $file
date "+/*   Updated: %Y/%m/%d %H:%M:%S by $USER         ###   ########.fr       */" >> $file
echo "/*                                                                            */
/* ************************************************************************** */

#include \"testlibft.h\"

void\ttest_$1((*ft)())
{
\tchar const *tests[] = {
\t};

\tfor (unsigned int i = 0 ; i < SIZE_ARRAY(tests) ; i++)
\t{
\t\tif ($1(tests[i]) == ft(tests[i]))
\t\t\tprintf(GREEN);
\t\telse
\t\t\tprintf(RED);
\t\tprintf(\".\");
\t}
\tprintf(END);
}" >> $file
