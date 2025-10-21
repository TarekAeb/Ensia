# Exo1
### a.

My computer has 3 network interfaces: eno1, lo, wlo1.

### b.

It has three interfaces because:

- `eno1` is likely a wired Ethernet interface.
- `lo` is the loopback interface used for internal communication within the host.
- `wlo1` is likely a wireless network interface.

### c. The IP address of each interface is:

- `eno1`: 10.80.25.229
- `lo`: 127.0.0.1
- `wlo1`: 10.42.0.1

### d. The mac address of each interface is:

- `eno1`: e0:73:e7:d3:34:d8
- `lo`: 00:00:00:00:00:00 (loopback interface does not have a MAC address)
- `wlo1`: ee:d9:87:ae:8a:5b

### e.

Some interfaces doesn't have a MAC address because they are virtual interfaces (like `lo` for loopback) or they are not physical network interfaces.

# Exo2
www.algeria.dz didn't respond to ping requests, it is most likely that there is no server there.

# Exo3

### a.
traceroute www.mit.edu
```
 const@robot: traceroute www.mit.edu
traceroute to www.mit.edu (23.55.149.130), 30 hops max, 60 byte packets
 1  OPNsense.localdomain (10.80.1.11)  0.069 ms  0.161 ms  0.057 ms
 2  192.168.160.1 (192.168.160.1)  1.697 ms  1.679 ms  1.520 ms
 3  192.168.174.89 (192.168.174.89)  1.244 ms  1.287 ms  1.340 ms
 4  * * *
 5  * * *
 6  * * *
 7  192.168.223.133 (192.168.223.133)  10.045 ms  9.552 ms  10.835 ms
 8  172.28.123.2 (172.28.123.2)  11.818 ms  11.843 ms  12.152 ms
 9  193.251.154.82 (193.251.154.82)  26.180 ms  27.430 ms  28.444 ms
10  193.251.131.44 (193.251.131.44)  29.851 ms  29.202 ms  27.612 ms
11  193.251.254.160 (193.251.254.160)  25.763 ms  26.049 ms  26.183 ms
12  lo1.r04.stem01.mrs01.fab.aloha-jmannil.netarch.akamai.com (184.25.96.25)  25.799 ms lo1.r03.stem01.mrs01.fab.aloha-jmannil.netarch.akamai.com (184.25.96.24)  32.043 ms lo1.r04.stem01.mrs01.fab.aloha-jmannil.netarch.akamai.com (184.25.96.25)  24.442 ms
13  lo1.r04.spine04.mrs01.fab.aloha-jmannil.netarch.akamai.com (184.25.96.21)  24.372 ms lo1.r03.spine03.mrs01.fab.aloha-jmannil.netarch.akamai.com (184.25.96.16)  32.789 ms lo1.r01.spine02.mrs01.fab.aloha-jmannil.netarch.akamai.com (184.25.96.10)  26.834 ms
14  lo1.r04.leaf01.mrs01.fab.aloha-jmannil.netarch.akamai.com (184.25.96.5)  27.709 ms lo1.r03.leaf01.mrs01.fab.aloha-jmannil.netarch.akamai.com (184.25.96.4)  26.214 ms lo1.r01.leaf01.mrs01.fab.aloha-jmannil.netarch.akamai.com (184.25.96.2)  25.582 ms
15  vlan100.r03.tor01.mrs01.fab.aloha-jmannil.netarch.akamai.com (184.25.100.1)  30.871 ms  30.548 ms  30.789 ms
16  * * *
17  * * *
18  * * *
19  * * *
20  * * *
21  * * *
22  * * *
23  * * *
24  * * *
25  * * *
26  * * *
27  * * *
28  * * *
29  * * *
30  * * *
```

### b.
there are 30 devices between mit and my device
### c.
Between which two routers do packets cross the Atlantic Ocean?
vlan100.r03.tor01.mrs01.fab.aloha-jmannil.netarch.akamai.com and the next one (which is not responding to traceroute requests)
### d.
At split 9 destinations diverge


# Exo4

# Exo5
### a. The Ip address of ensia.edu.dz 
197.140.11.217

### b. The IP address of yahoo.fr
13.248.158.7
76.223.84.192
- It has more than one IP address because it uses multiple servers to handle requests, which helps with load balancing and redundancy.

### c. The IP address of google.com

### d.
The IP addresses can change for several reasons:
- DNS load balancing / round-robin: Google’s DNS returns different IPs in rotation to distribute the load.
- CDN (Content Delivery Network): you might get directed to a closer data center.
- Caching: your ISP or system might update its DNS cache periodically.
### e. the name of IP address 127.0.0.1
localhost, what is special about it is that it is the loopback address, used to establish an IP connection to the same machine or computer being used by the end-user.

# Exo6
a. The opened ports on my computer are too much
b. The remote adresses that comunicate with my computer are:
- https
- webaccess
- serverview-icc
- bootps