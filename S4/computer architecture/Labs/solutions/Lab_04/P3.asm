.data
    prompt_a: .ascii "Enter the value of a: "
    prompt_b: .ascii "Enter the value of b: "
    prompt_c: .ascii "Enter the value of c: "
    result: .ascii "The value of s is: "
    newline: .ascii "\n"
.text

.global main

main:
    # Print the prompt for a
    la a0, prompt_a
    li a7, 4 
    ecall

    # Read a
    li a7, 5
    ecall
    mv t0, a0  # Store a in t0

    # Print the prompt for b
    la a0, prompt_b
    li a7, 4  
    ecall

    # Read b
    li a7, 5
    ecall
    mv t1, a0  # Store b in t1

    # Print the prompt for c
    la a0, prompt_c
    li a7, 4
    ecall

    # Read c
    li a7, 5
    ecall
    mv t2, a0  # Store c in t2

    # Calculate s = (a + b) - (c + 101)
    add t3, t0, t1  # t3 = a + b
    addi t4, t2, 101  # t4 = c + 101
    sub t5, t3, t4  # t5 = (a + b) - (c + 101)

    # Print the result prompt
    la a0, result
    li a7, 4
    ecall

    # Print the value of s
    mv a0, t5
    li a7, 1
    ecall

    # Print a newline
    la a0, newline
    li a7, 4
    ecall

    # Exit the program
    li a7, 10
    ecall