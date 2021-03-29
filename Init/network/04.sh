route | grep -oP '^0.0.0.0\s+\K[\w.]+'
echo
ip route | grep -oP 'default via \K[\w.]+'
