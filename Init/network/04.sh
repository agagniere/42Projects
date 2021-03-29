route | grep -oP '^0.0.0.0\s+\K[\d.]+'
ip route | grep -oP 'default via \K[\d.]+'
