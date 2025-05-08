.data
array:  .word  -1, 22, 8, 35, 5, 4, 11, 2, 1, 78
n:      .word  10
newline: .asciz "\n"

.text
.globl main

main:
    li t0, 0              
    li t1, 9              # hi 
    la t2, array          # base address of array

    jal ra, quicksort


    la t2, array          # reload base address
    li t3, 0              # i = 0

print_loop:
    lw t4, 0(t2)          
    mv a0, t4
    li a7, 1
    ecall

    li a0, 32             # ASCII code for ' '
    li a7, 11
    ecall

    addi t2, t2, 4        
    addi t3, t3, 1        # i++

    li t5, 10             # number of elements
    blt t3, t5, print_loop

    la a0, newline
    li a7, 4
    ecall

# exit
    li a7, 10
    ecall

quicksort:
    bge t0, t1, quicksort_return

    # Save registers
    addi sp, sp, -16
    sw t0, 0(sp)
    sw t1, 4(sp)
    sw ra, 8(sp)
    sw t2, 12(sp)

    jal ra, partition
    mv t3, a0            # p = returned value

    # quicksort(A, lo, p-1)
    lw t0, 0(sp)
    lw t2, 12(sp)
    addi t1, t3, -1
    jal ra, quicksort

    # quicksort(A, p+1, hi)
    lw t0, 0(sp)
    lw t1, 4(sp)
    lw t2, 12(sp)
    addi t0, t3, 1
    jal ra, quicksort

    # Restore ra
    lw ra, 8(sp)
    addi sp, sp, 16

quicksort_return:
    ret

# partition(A, lo, hi)
partition:
    # pivot = A[hi]
    slli t4, t1, 2
    add t4, t2, t4
    lw t5, 0(t4)          # pivot = A[hi]

    # i = lo - 1
    addi t6, t0, -1       # i = lo-1

    mv s0, t0             # j = lo

partition_loop:
    bge s0, t1, partition_end

    slli s1, s0, 2
    add s1, t2, s1
    lw s2, 0(s1)

    bgt s2, t5, skip_swap

    # i = i + 1
    addi t6, t6, 1

    # swap (A[i], A[j])
    slli s3, t6, 2
    add s3, t2, s3
    lw s4, 0(s3)          # A[i]

    sw s2, 0(s3)          # A[i] = A[j]
    sw s4, 0(s1)          # A[j] = A[i]

skip_swap:
    addi s0, s0, 1
    j partition_loop

partition_end:
   # swap (A[i+1], A[hi])
    addi t6, t6, 1
    slli s1, t6, 2
    add s1, t2, s1
    lw s2, 0(s1)   

    slli t4, t1, 2
    add t4, t2, t4
    lw s4, 0(t4)          # A[hi]

    sw s4, 0(s1)          # A[i+1] = A[hi]
    sw s2, 0(t4)          # A[hi] = A[i+1]

#return i+1
    mv a0, t6
    ret
