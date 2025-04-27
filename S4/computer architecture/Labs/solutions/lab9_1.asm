.data
prompt:     .asciz "Enter a number: "
resultMsg:  .asciz "Result: "

.text
.globl main

# power(a0=x, a1=n) => a0 = x^n
power:
    mv t1, a0        # t1 = x
    li t0, 1         # t0 = result = 1
power_loop:
    beq a1, x0, power_done
    mul t0, t0, t1
    addi a1, a1, -1
    j power_loop
power_done:
    mv a0, t0
    jr ra

# times(a0=x, a1=n) => a0 = x * n
times:
    mul a0, a0, a1
    jr ra

# exp(a0=x) => a0 = x^5 + 6x^3 + 3x + 4
exp:
    addi sp, sp, -12
    sw ra, 0(sp)
    sw a0, 4(sp)

    # x^5
    lw a0, 4(sp)
    li a1, 5
    call power
    mv t0, a0

    # 6 * x^3
    lw a0, 4(sp)
    li a1, 3
    call power
    li a1, 6
    call times
    add t0, t0, a0

    # 3 * x
    lw a0, 4(sp)
    li a1, 3
    call times
    add t0, t0, a0

    # +4
    addi t0, t0, 4
    mv a0, t0

    lw ra, 0(sp)
    addi sp, sp, 12
    jr ra

main:
    li a7, 4
    la a0, prompt
    ecall

    li a7, 5
    ecall            # input in a0

    call exp         # result in a0

    li a7, 4
    la a0, resultMsg
    ecall

    li a7, 1         # print result
    ecall

    li a7, 10        # exit
    ecall
