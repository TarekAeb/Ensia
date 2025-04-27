# Program P1: Print "Salem" N times
.data
    prompt: .asciz "Enter a number: "
    salem: .asciz "Salem\n"

.text
.globl main

main:
    # Print prompt
    la a0, prompt
    li a7, 4
    ecall
    
    # Read integer N
    li a7, 5
    ecall
    mv t0, a0  # Store N in t0

print_salem:
    beqz t0, end  # If N == 0, exit loop

    # Print "Salem"
    la a0, salem
    li a7, 4
    ecall

    # Decrement N
    addi t0, t0, -1
    j print_salem

end:
    li a7, 10  # Exit program
    ecall
