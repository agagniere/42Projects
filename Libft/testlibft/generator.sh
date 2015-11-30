# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generator.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 15:25:08 by angagnie          #+#    #+#              #
#    Updated: 2015/11/30 16:50:45 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

file="src/test_"$2".cpp"
echo "Generating" $file
echo "// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test_$2.c\t\t\t\t\t\t\t\t\t\t:+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: $USER <$USER@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //" > $file
date "+//   Created: %Y/%m/%d %H:%M:%S by $USER          #+#    #+#             //" >> $file
date "+//   Updated: %Y/%m/%d %H:%M:%S by $USER         ###   ########.fr       //" >> $file
echo "//                                                                            //
// ************************************************************************** //

#include \"testlibft.h\"

void\ttest_$2($1 (*ft)($3 $4))
{
\t$3 const tests[] = {
\t\t// some $3 values
\t};

\tfor (unsigned int i = 0 ; i < SIZE_ARRAY(tests) ; i++)
\t{
\t\tMARK($2(tests[i]) == ft(tests[i]));
\t}
\tprintf(END);
}" >> $file
echo "void\ttest_$2($1 (*ft)($3 $4));" >> hdr/testlibft.h
