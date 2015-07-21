ldapsearch -LLL '(last-name=*BON*)' -S last-name | grep 'BON' | wc -l | tr -d ' '
