from scapy.all import *

# Simulate an ICMP Destination Unreachable message
ip_header = IP(src="192.168.1.100", dst="8.8.8.8")
udp_segment = UDP(sport=1234, dport=80)

icmp_error = IP(src="8.8.8.8", dst="192.168.1.100") / \
             ICMP(type=3, code=3) / \
             ip_header / \
             udp_segment

# Send ICMP packet
send(icmp_error)

print("ICMP Destination Unreachable message sent.")
