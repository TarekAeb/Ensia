from scapy.all import *

def send_ping(target_ip):
    message = "Hello from sender!"
    icmp_request = IP(dst=target_ip) / ICMP(type=8) / message

    print(f"Sending ICMP Echo Request to {target_ip}")
    response = sr1(icmp_request, timeout=2)

    if response:
        print("Received response:")
        print(response.show())
    else:
        print("No response received.")

if __name__ == "__main__":
    target = "192.168.100.100"   # Receiver IP address
    send_ping(target)
