.data
    equal_message:      .asciz "The two integers are equal\n"
    not_equal_message:  .asciz "The two integers are not equal\n"
    first_input:        .asciz "Enter the first input: "
    second_input:       .asciz "Enter the second input: "

.text
.globl main

.macro print(%Label)
    la a0, %Label
    li a7, 4  
    ecall
.end_macro

main:
    # Print the first prompt
    print(first_input)
    
    # Read first integer
    li a7, 5
    ecall
    mv t0, a0  # Store first integer in t0

    # Print the second prompt
    print(second_input)

    # Read second integer
    li a7, 5
    ecall
    mv t1, a0  # Store second integer in t1

    # Compare integers
    beq t0, t1, Equal  # If t0 == t1, jump to Equal

    # If not equal, print the not equal message
    print(not_equal_message)
    j Exit  # Jump to exit to prevent falling through

Equal:
    print(equal_message)

Exit:
    li a7, 10  # Exit syscall
    ecall
