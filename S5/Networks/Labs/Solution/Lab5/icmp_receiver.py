from scapy.all import *

def handle_packet(packet):
    if ICMP in packet and packet[ICMP].type == 8:  # ICMP Echo Request
        print("ICMP Echo Request received:")
        packet.show()

        # Build an ICMP Echo Reply
        reply = IP(src=packet[IP].dst, dst=packet[IP].src) / ICMP(type=0) / "Hello from receiver!"

        print("Sending ICMP Echo Reply...")
        send(reply, verbose=0)

if __name__ == "__main__":
    print("Listening for ICMP Echo Requests...")
    sniff(filter="icmp", prn=handle_packet)
