.data
input_file_prompt:  .asciz "Enter the input file name: "
output_file_prompt: .asciz "Enter the output file name: "
error_message:      .asciz "Error: Unable to open the input file.\n"
buffer:             .space 256         # Shared buffer for file content
filename_in:        .space 256         # Buffer for input filename
filename_out:       .space 256         # Buffer for output filename

.text
.globl main

main:
    # Prompt for input file name
    la a0, input_file_prompt
    li a7, 4
    ecall

    # Read input filename
    la a0, filename_in
    li a1, 256
    li a7, 8
    ecall

    # Strip newline from input filename
    la t2, filename_in
strip_newline_in:
    lb t3, 0(t2)
    beqz t3, end_strip_in
    li t4, 10           # ASCII '\n'
    beq t3, t4, replace_in
    addi t2, t2, 1
    j strip_newline_in
replace_in:
    sb zero, 0(t2)
end_strip_in:

    # Open input file (read-only)
    la a0, filename_in
    li a1, 0            # O_RDONLY
    li a7, 1024         # syscall: open
    ecall

    bltz a0, input_file_error
    mv t0, a0           # Save input file descriptor

    # Prompt for output file name
    la a0, output_file_prompt
    li a7, 4
    ecall

    # Read output filename
    la a0, filename_out
    li a1, 256
    li a7, 8
    ecall

    # Strip newline from output filename
    la t2, filename_out
strip_newline_out:
    lb t3, 0(t2)
    beqz t3, end_strip_out
    li t4, 10           # ASCII '\n'
    beq t3, t4, replace_out
    addi t2, t2, 1
    j strip_newline_out
replace_out:
    sb zero, 0(t2)
end_strip_out:

# Open output file (write-only | create | truncate)
la a0, filename_out     # filename
li a1, 578              # flags = O_WRONLY | O_CREAT | O_TRUNC
li a2, 0666             # mode = rw-rw-rw-
li a7, 1024             # syscall: open (RARS)
ecall

    bltz a0, close_input_file
    mv t1, a0           # Save output file descriptor

copy_loop:
    # Read from input file
    mv a0, t0
    la a1, buffer
    li a2, 256
    li a7, 63           # syscall: read
    ecall

    blez a0, close_files
    mv t2, a0           # Save number of bytes read

    # Write to output file
    mv a0, t1
    la a1, buffer
    mv a2, t2
    li a7, 64           # syscall: write
    ecall

    j copy_loop

input_file_error:
    la a0, error_message
    li a7, 4
    ecall
    j exit

close_input_file:
    mv a0, t0
    li a7, 57           # syscall: close
    ecall
    j exit

close_files:
    mv a0, t0
    li a7, 57
    ecall

    mv a0, t1
    li a7, 57
    ecall

exit:
    li a7, 10           # syscall: exit
    ecall
