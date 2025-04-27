.data
menu:        .asciz "Choose a conversion:\n1. Temperature\n2. Number\n"
fun_temp:    .asciz "Choose a function:\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n"
fun_num:     .asciz "Choose a function:\n1. Decimal to Binary\n2. Binary to Decimal\n"
input_msg:   .asciz "Enter the number:"
result_msg:  .asciz "Result: "
again_msg:   .asciz "Do you want to try again?"
newline:     .asciz "\n"
temp_input_msg: .asciz "Enter temperature:"

.text
.globl main

# Macro to display dialog with message and get integer input
.macro dialog_input(%msg, %reg)
    li a7, 51  # syscall code for displaying a message dialog and getting integer input
    la a0, %msg # load the address of the message into a0
    li a1, 0 #No buttons
    mv a2, x0 #No title
    ecall
    mv %reg, a0 # move the input from a0 to the specified register
.end_macro

# Macro to display dialog with message and get float input
.macro dialog_float_input(%msg, %freg)
    li a7, 52  # syscall code for displaying a message dialog and getting float input
    la a0, %msg # load the address of the message into a0
    li a1, 0 #No buttons
    mv a2, x0 #No title
    ecall
    fmv.s %freg, fa0 # move the input from fa0 to the specified register
.end_macro

main:
    li t1, 1  # Temperature option
    li t2, 2  # Number option

    # Show menu using dialog box
    dialog_input(menu, t0) #display the main menu and get the input

    beq t0, t1, temp  # If choice is 1, go to temperature conversion
    beq t0, t2, num   # If choice is 2, go to number conversion

    j main  # If invalid choice, show menu again

temp:
    # Show temperature conversion menu
    dialog_input(fun_temp, t0) #display the temp menu and get the input

    li t1, 1 # Celsius to Fahrenheit
    li t2, 2 # Fahrenheit to Celsius

    beq t0, t1, cel_fah  # If choice is 1, Celsius to Fahrenheit
    beq t0, t2, fah_cel  # If choice is 2, Fahrenheit to Celsius
    j temp #invalid input, go back to temp

# F = (°C × 1.8) + 32
cel_fah:
    # Get Celsius input
    dialog_float_input(temp_input_msg, fa0)

    flt.s f1, 1.8
    flt.s f2, 32.0

    fmul.s f3, fa0, f1  # f3 = Celsius * 1.8
    fadd.s f3, f3, f2   # f3 = (Celsius * 1.8) + 32

    # Print result message
    li a7, 4
    la a0, result_msg
    ecall

    # Print Fahrenheit result
    fmv.s fa0, f3
    li a7, 2 #print float
    ecall

    j main
num:
    li a7, 4
    la a0, fun_num
    ecall
    j main
fah_cel:
    j main