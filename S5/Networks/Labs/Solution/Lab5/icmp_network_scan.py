from scapy.all import *

def scan_network(network):
    print(f"Scanning the network: {network}")

    # Generate ICMP Echo Request packets for each IP address on the network
    ans, unans = sr(IP(dst=network)/ICMP(type=8), timeout=2, verbose=0)

    # Process responses received
    print("Hosts responding to ICMP Echo Request:")
    for sent, received in ans:
        print(f"{received.src} is alive.")

    # Non-responding hosts
    if unans:
        print("\nHosts not responding:")
        for sent in unans:
            print(sent.dst)

# Scan a complete network
if __name__ == "__main__":
    scan_network("192.168.100.0/24")
