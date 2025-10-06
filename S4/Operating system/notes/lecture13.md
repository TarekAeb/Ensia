# Lecture 13: Hard Disk Drive
The disk contains a number of platters, each platter has two surfaces, and each surface has a number of tracks. Each track is divided into sectors. The disk drive has a read/write head that moves over the surface of the platter to read or write data.

# Hard disk drive Scheduling algorithms
1. First Come First Serve (FCFS)
2. Shortest Seek Time First (SSTF): serve the newarest request
3. SCAN: move the head in one direction until the end of the disk, then reverse direction
4. C-SCAN: move the head in one direction until the end of the disk, then jump to the other end and continue in the same direction
5. LOOK: similar to SCAN, but only goes as far as the last request in the direction of travel
6. C-LOOK: similar to C-SCAN, but only goes as far as the last request in the direction of travel


# Lecture 14: Operating system security

Operating system security is the protection of the operating system from unauthorized access, use, or destruction. It involves implementing security measures to protect the operating system and its resources from threats such as malware, viruses, and unauthorized access.
## Security services:
*necessary*
1. Authentication: verifying the identity of a user or system what you are/ have/ know
2. Confidentiality: protecting information from unauthorized access
3. Integrity: ensuring that information is accurate and reliable
4. Availability: ensuring that information and resources are available to authorized users when needed
5. Non-repudiation: ensuring that a user cannot deny having performed an action
*not necessary*
6. Accountability: ensuring that users are held responsible for their actions
7. Privacy: ensuring that personal information is protected from unauthorized access
8. Auditing: monitoring and recording system activity to detect and respond to security incidents
9. Authentication: verifying the identity of a user or system (define access rights)

## Security threats:
1. Configuration & programming errors: bugs in the operating system or applications that can be exploited by attackers
2. Denial of service (DoS) attacks: overwhelming a system with requests to make it unavailable to legitimate users
3. Squatting: illegally hosting a domain name or IP address
4. Malware: malicious software designed to harm or exploit a system
5. Spoofing: impersonating a user or system to gain unauthorized access
6. Social engineering: manipulating users into revealing sensitive information or performing actions that compromise security
7. Undesarible: spams, pop ups, and other unwanted content that can compromise security
8. Reconnaissance: gathering information about a system or network to identify vulnerabilities

## Malware:
Is a program designed to cause harm to a  operating system

### Types of malware:
1. Virus: a program that attaches itself to another program and spreads when the infected program is executed
2. Worm: a self-replicating program that spreads across networks without user intervention
3. Trojan horse: a program that appears to be legitimate but contains malicious code
4. Rootkit
5. Bot: a program that allows an attacker to control a compromised system remotely
6. Spyware: a program that collects information about a user without their knowledge
7. Ransomware: a program that encrypts a user's files and demands payment for the decryption key
8. keylogger: a program that records keystrokes to capture sensitive information such as passwords
9. backdoor: a program that allows an attacker to bypass normal authentication and gain unauthorized access to a system
10. popup: a program that displays unwanted advertisements or messages on a user's screen
11. hoax: a false or misleading message designed to trick users into taking action

## Trap door:
is a piece of code that "intentionally" inserted into a program by the developer to allow access, for maintenance or debugging purposes. It is a security risk because it can be exploited by attackers to gain unauthorized access to a system.

# Operating system protection and mechan tools:
1. Antivirus software: detects and removes malware from a system
2. Firewalls: monitors and controls incoming and outgoing network traffic based on predetermined security rules
3. Anti-spyware: detects and removes spyware from a system
4. Integrity checkers: monitors files and directories for unauthorized changes
5. IDS (Intrusion Detection System): monitors network traffic for suspicious activity and alerts administrators
6. IPS (Intrusion Prevention System): monitors network traffic for suspicious activity and takes action to block or prevent it
7. Event logging: records system activity to detect and respond to security incidents