# Init

## Network

#### List of interfaces

Get the list of the network interfaces of the machine without displaying any detail
for these interfaces. Only the list of names.

```shell
> netstat --interfaces --all | tail +3 | cut -d' ' -f1
eth0
eth1
eth2
eth3
lo
wifi0
wifi1
wifi2
```
```shell
> ip link | grep -oP '^\d+: \K\w+'
eth0
eth1
eth2
lo
wifi0
wifi1
wifi2
eth3
```
```shell
> ifconfig -a | grep -oP '^\w+'
eth0
eth1
eth2
eth3
lo
wifi0
wifi1
wifi2
```

#### Ethernet Broadcast Address

Identify and display the Ethernet interface broadcast address

```shell
> ip address | grep -P '^\d+: e' -A2 | grep -oP 'brd \K[\d.]+' | sort --unique
xx.xx.127.255
xx.xx.255.255
```
```shell
> ifconfig -a | grep -P '^e' -A3 | grep -oP 'broadcast \K[\d.]+'
xx.xx.127.255
xx.xx.255.255
```

#### Wi-Fi card MAC address

```shell
> ip address | grep -P '\d+: w' -A1 | grep -oP '([a-z0-9]{2}:){5}[a-z0-9]{2}'
d0:xx:xx:xx:xx:1f
d0:xx:xx:xx:xx:20
d2:xx:xx:xx:xx:1f
```
```shell
> ifconfig -a | grep -P '^w' -A5 | grep -oP 'ether \K[\w:]+'
d0:xx:xx:xx:xx:1f
d0:xx:xx:xx:xx:20
d2:xx:xx:xx:xx:1f
```

#### Default gateway

Identifiy the default gateway in the routing table

```shell
> netstat --route | grep -oP '^0.0.0.0\s+\K[\w.]+'
192.168.1.1
> route | grep -oP '^0.0.0.0\s+\K[\w.]+'
192.168.1.1
```
```shell
> ip route | grep -oP 'default via \K[\w.]+'
192.168.1.1
```
