# Init : Network

## 1. List of interfaces

Get the list of the network interfaces of the machine without displaying any detail
for these interfaces. Only the list of names.

```console
$ netstat --interfaces --all | tail +3 | cut -d' ' -f1
eth0
eth1
eth2
eth3
lo
wifi0
wifi1
wifi2
```
```console
$ ip link | grep -oP '^\d+: \K\w+'
eth0
eth1
eth2
lo
wifi0
wifi1
wifi2
eth3
```
```console
$ ifconfig -a | grep -oP '^\w+'
eth0
eth1
eth2
eth3
lo
wifi0
wifi1
wifi2
```

## 2. Ethernet Broadcast Address

Identify and display the Ethernet interface broadcast address

```console
$ ip address | grep -P '^\d+: e' -A2 | grep -oP 'brd \K[\d.]+' | sort --unique
xx.xx.127.255
xx.xx.255.255
```
```console
$ ifconfig -a | grep -P '^e' -A3 | grep -oP 'broadcast \K[\d.]+'
xx.xx.127.255
xx.xx.255.255
```

## 3. Wi-Fi card MAC address

```console
$ ip address | grep -P '\d+: w' -A1 | grep -oP '([a-f0-9]{2}:){5}[a-f0-9]{2}'
d0:xx:xx:xx:xx:1f
d0:xx:xx:xx:xx:20
d2:xx:xx:xx:xx:1f
```
```console
$ ifconfig -a | grep -P '^w' -A5 | grep -oP 'ether \K[\w:]+'
d0:xx:xx:xx:xx:1f
d0:xx:xx:xx:xx:20
d2:xx:xx:xx:xx:1f
```

## 4. Default gateway

Identifiy the default gateway in the routing table

```console
$ netstat --route | grep -oP '^0.0.0.0\s+\K[\d.]+'
192.168.1.1
$ route | grep -oP '^0.0.0.0\s+\K[\d.]+'
192.168.1.1
$ ip route | grep -oP 'default via \K[\d.]+'
192.168.1.1
```

## 5. DNS used

Identify the IP address of the DNS that responds to a given url

```console
$ nslookup slash16.org | grep -oP 'Server:\s+\K[\d.]+'
xx.xx.84.2
$ dig slash16.org | grep -oP 'SERVER: [\d.#]+\(\K[\d.]+'
xx.xx.84.2
```

## 8. Provider of a given website

```console
$ whois slash16.org | grep -oP '^Name Server: \K[\w.-]+'
NS-1236.AWSDNS-26.ORG
NS-144.AWSDNS-18.COM
NS-686.AWSDNS-21.NET
NS-1989.AWSDNS-56.CO.UK
```

## 9. External IP

```console
$ nslookup 42.fr | grep -oP '^Address: \K[\d.]+'
163.172.250.13
163.172.250.12
$ dig +short 42.fr
163.172.250.13
163.172.250.12
```
