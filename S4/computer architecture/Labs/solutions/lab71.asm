.data
M: .word 0:10
Input: .asciz "Enter the index number: "
Sum: .asciz "The sum of all the array inputs is: "

.text
.globl main

.macro print_message(%label)
    # print the message
    li a7, 4
    la a0, %label
    ecall
.end_macro

.macro print_integer(%reg)
    # print the integer
    li a7, 1
    mv a0, %reg
    ecall
.end_macro

.macro read_Input(%reg)
    # read an integer
    li a7, 5
    ecall
    mv %reg, a0
.end_macro

main:
    # Load the address of M into a5
    la a5, M
    li t1, 0      # i = 0
    li t2, 10     # n = 10
    mv a3, a5    # a3 = &M[0]
    li a4, 0      # sum = 0

for:
    bge t1, t2, EndLoop
    print_message(Input)
    print_integer(t1)
    read_Input(a2)

    

    sw a2, 0(a3)         # Store input in M[i]
    add a4, a4, a2       # Update sum
    addi t1, t1, 1       # i = i + 1
    slli t3, t1, 2       # t3 = i * 4 (byte offset)
    add a3, a5, t3       # a3 = &M[i]
    j for                # Jump back to the start of the loop

EndLoop:
    print_message(Sum)
    print_integer(a4)

    # Exit the program
    li a7, 10
    ecall