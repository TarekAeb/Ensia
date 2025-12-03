from scapy.all import *

# C r e a t e an ARP p a c k e t t o r e q u e s t t h e MAC a d d r e s s a s s o c i a t e d with an IP a d d r e s s

def create_arp_request ( target_ip , source_ip ) :

    arp_request = ARP( pdst=target_ip , psrc=source_ip , op=1) # op=1 f o r an ARP r e q u e s t

    ether_layer = Ether(dst="ff:ff:ff:ff:ff:ff")# E t h e r n e t frame f o r b r o a d cast

    arp_packet = ether_layer / arp_request

    return arp_packet

 # Send t h e ARP p a c k e t and c a p t u r e t h e r e s p o n s e
def send_and_receive_arp( packet ) :
    print("Sending ARP request . . ." )
    response , unanswered = srp ( packet , timeout =5, verbose=False )
    return response

 # Analyze t h e ARP r e s p o n s e
def analyze_response ( response ) :
    if response :
        for sent , received in response :
            print(f"Target IP address : {received.psrc} ")
            print(f"Associat e d MAC a d d r e s s :{received.hwsrc } ")
        else :
            print(f"No response received. The target machine may be unreachable")

if __name__ == "__main__":
    target_ip = "10.80.0.0"
    source_ip = "10.80.43.174"

    arp_packet = create_arp_request(target_ip, source_ip)
    print ("Arp packet created:")
    arp_packet.show()

    response = send_and_receive_arp(arp_packet)
    
    analyze_response(response)
