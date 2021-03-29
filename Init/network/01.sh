netstat --interfaces --all | tail +3 | cut -d' ' -f1
echo
ip link | grep -oP '^\d+: \K\w+'
echo
ifconfig -a | grep -oP '^\w+'
