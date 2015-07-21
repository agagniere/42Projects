#export FT_NBR1=\\\'\?\"\\\"\'\\
#export FT_NBR2=rcrdmddd
echo 'obase=13' > tmp ; echo "ibase=5\n$FT_NBR1 + $FT_NBR2" | tr "\'\"\?\!" "0234" | tr '\\' '1' | tr "mrdoc" "01234" | bc >> tmp ; cat tmp | bc | tr '0123456789ABC' 'gtaio luSnemf'