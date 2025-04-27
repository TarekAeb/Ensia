.data
Input: .asciz "Enter the number n: "
space: .asciz " "
line: .asciz "\n"

.text
.globl main

.macro print_message(%label)
    li a7, 4
    la a0, %label
    ecall
.end_macro

.macro sbrk(%n)
    
    mul t0, %n, %n
    li t1, 4
    mul a0, t0, t1
    li a7, 9
    ecall
.end_macro

.macro print_integer(%reg)
    li a7, 1
    mv a0, %reg
    ecall
.end_macro

.macro read_input(%reg)
    li a7, 5
    ecall
    mv %reg, a0
.end_macro

main:
    print_message(Input)
    read_input(s1)         # s1 = n
    sbrk(s1)               
    mv s2, a0              

    li s3, 0               # i = 0 (s3)

OuterLoop:
    bge s3, s1, Exit       # if i >= n, exit
    li s4, 0               # j = 0 (s4)

InnerLoop:
    bge s4, s1, EndInner

    # offset = (i * n + j) * 4
    mul t0, s3, s1         # t0 = i * n
    add t0, t0, s4         # t0 = i * n + j
    slli t0, t0, 2         # t0 = offset in bytes
    add t1, s2, t0         # t1 = &a[i][j]

    #i+j
    add t2, s3, s4         # t2 = value

    # if (i > 0) value += a[i-1][j]
    blez s3, SkipI
    addi t3, s3, -1
    mul t4, t3, s1
    add t4, t4, s4
    slli t4, t4, 2
    add t4, s2, t4
    lw t5, 0(t4)
    add t2, t2, t5
SkipI:

    # if (j > 0) value += a[i][j-1]
    blez s4, SkipJ
    addi t3, s4, -1
    mul t4, s3, s1
    add t4, t4, t3
    slli t4, t4, 2
    add t4, s2, t4
    lw t5, 0(t4)
    add t2, t2, t5
SkipJ:

    sw t2, 0(t1)           # a[i][j] = value


    print_integer(t2)
    print_message(space)

    addi s4, s4, 1         # j++
    j InnerLoop

EndInner:
    print_message(line)
    addi s3, s3, 1         # i++
    j OuterLoop

Exit:
    li a7, 10
    ecall
