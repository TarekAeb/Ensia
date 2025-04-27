.data
file:   .asciz "/home/const/Documents/Study/Ensia/S4/computer architecture/Labs/solutions/dna.txt"
buffer: .space 100
msg_c:  .asciz "Number of C: "
msg_g:  .asciz "\nNumber of G: "
msg_total: .asciz "\nTotal : "
newline: .asciz "\n"

.text

li   a7, 1024
la   a0, file
li   a1, 0
li   a2, 0
ecall
mv   s6, a0

# Read from the file
mv   a0, s6
la   a1, buffer
li   a2, 100
li   a7, 63
ecall
mv   s7, a0              # s7 = number of bytes read

# Null-terminate the buffer
la   t0, buffer
add  t0, t0, s7
sb   zero, 0(t0)

# Count 'C' and 'G'
la   t0, buffer          # pointer to buffer
li   t1, 0               # t1 = C 
li   t2, 0               # t2 = G 
li   t5, 0		 # t3 = total
count_loop:
    lb   t3, 0(t0)
    beqz t3, print_counts    # end of string
    addi t5 , t5,1 
    li   t4, 'C'
    beq  t3, t4, count_c
    li   t4, 'G'
    beq  t3, t4, count_g
    j    next_char
count_c:
    addi t1, t1, 1
    j    next_char
count_g:
    addi t2, t2, 1
next_char:
    addi t0, t0, 1
    j    count_loop

print_counts:
    # Print "Number of C: "
    la   a0, msg_c
    li   a7, 4
    ecall
    # Print C count
    mv   a0, t1
    li   a7, 1
    ecall

    # Print "\nNumber of G: "
    la   a0, msg_g
    li   a7, 4
    ecall
    # Print G count
    mv   a0, t2
    li   a7, 1
    ecall

    # Print "\nTotal (C+G): "
    la   a0, msg_total
    li   a7, 4
    ecall
    # Print total
    mv  a0, t5
    li   a7, 1
    ecall

    # Print newline (optional)
    la   a0, newline
    li   a7, 4
    ecall

    # Exit
    li   a7, 10
    ecall