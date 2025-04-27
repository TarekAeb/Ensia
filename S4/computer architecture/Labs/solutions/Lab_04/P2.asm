.data
    prompt:     .asciz "Enter your full name: "
    salam:      .asciz "Salam "
    full_name:  .space 100  # Reserve 100 bytes for the full name

.text
.globl main

main:
    # Print the prompt
    la a0, prompt
    li a7, 4  
    ecall

    # Read the full name
    la a0, full_name
    li a1, 100  # maximum number of bytes to read
    li a7, 8    
    ecall

    # Print "Salam: " followed by the full name
    la a0, salam
    li a7, 4  
    ecall

    la a0, full_name
    li a7, 4  
    ecall

    # Exit the program
    li a7, 10  # syscall number for exit
    ecall