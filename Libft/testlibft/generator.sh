# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generator.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 15:25:08 by angagnie          #+#    #+#              #
#    Updated: 2015/12/01 13:15:22 by angagnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

file="src/test_"$2".cpp"
header="hdr/testlibft.hpp"

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
" >> $file

if [ "$#" -gt "3" ]; then
	echo "void\ttest_$2($1 (*ft)($3, $4))" >> $file
	echo "void\ttest_$2($1 (*ft)($3, $4));" >> $header
else
	echo "void\ttest_$2($1 (*ft)($3))" >> $file
	echo "void\ttest_$2($1 (*ft)($3));" >> $header
fi

echo "{
\tchar\tbuf[BUFSIZE];
" >> $file

if [ "$#" -gt "3" ]; then
	echo "\tfun_tester($2, ft, clear_buf(buf, \"Some value\"), $4);\n}" >> $file
else
	echo "\tfun_tester($2, ft, clear_buf(buf, \"Some value\"));\n}" >> $file
fi