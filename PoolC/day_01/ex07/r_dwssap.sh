cat /etc/passwd | sed '/#/d' | awk '{FS=":"}{if((NR+1)%2)print $1}' | rev | sort -r | sed -n $FT_LINE1,$FT_LINE2'p' | tr '\n' ',' | sed 's/,/, /g' | sed 's/\(.*\), /\1./' | tr -d '\n'
