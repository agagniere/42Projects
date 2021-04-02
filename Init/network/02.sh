ip address | grep -P '^\d+: e' -A2 | grep -oP 'brd \K[\d.]+' | sort --unique
echo
ifconfig -a | grep -P '^e' -A3 | grep -oP 'broadcast \K[\d.]+' | sort --unique
