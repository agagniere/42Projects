ip address | grep -P '\d+: w' -A1 | grep -oP '([a-f0-9]{2}:){5}[a-f0-9]{2}'
echo
ifconfig -a | grep -P '^w' -A5 | grep -oP 'ether \K[\w:]+'