.data
  menu_prompt: .string "\nSelect a conversion function:\n0: Convert between Binary and Decimal\n1: Convert between Celsius and Fahrenheit\nYour choice: "
  binary_decimal_prompt: .string "\nSelect conversion type:\n0: Binary to Decimal\n1: Decimal to Binary\nYour choice: "
  temperature_prompt: .string "\nSelect temperature conversion:\n0: Celsius to Fahrenheit\n1: Fahrenheit to Celsius\nYour choice: "
  input_prompt: .string "\nEnter the number you want to convert (ensure it is valid): "
  output_message: .string "\nConversion result: "
  retry_prompt: .string "\nWould you like to perform another conversion?\n0: Yes\n1: No\nYour choice: "

.text
beq zero, zero, main_loop

binary_decimal_conversion:
  addi t0, zero, 0 # store the result
  addi t1, zero, 1 # variable used in converting
  beq a1, zero, binary_to_decimal
  
binary_to_decimal:
binary_to_decimal_loop:
  bge zero, a0, conversion_done
  addi t3, zero, 2
  rem t2, a0, t3
  mul t2, t2, t1
  add t0, t0, t2
  addi t3, zero, 10
  mul t1, t1, t3
  addi t3, zero, 2
  div a0, a0, t3
  beq zero, zero, binary_to_decimal_loop

decimal_to_binary:
decimal_to_binary_loop:
  bge zero, a0, conversion_done
  addi t3, zero, 10
  rem t2, a0, t3
  beq t2, zero, skip_bit_addition
  add t0, t0, t1
skip_bit_addition:
  addi t3, zero, 2
  mul t1, t1, t3
  addi t3, zero, 10
  div a0, a0, t3
  beq zero, zero, decimal_to_binary_loop

conversion_done:
  addi a0, t0, 0
  jalr zero, 0(ra)
  
temperature_conversion:
  beq a1, zero, fahrenheit_to_celsius
  addi a0, a0, -32
  addi t3, zero, 5
  mul a0, a0, t3
  addi t3, zero, 9
  div a0, a0, t3
  beq zero, zero, temperature_conversion_done
  
fahrenheit_to_celsius:
  li t0, 9         
  li t3, 5
  mul a0, a0, t0
  div a0, a0, t3
  addi a0, a0, 32

temperature_conversion_done:
  jalr zero, 0(ra)

# Main loop
main_loop:
  li a7, 51
  la a0, menu_prompt
  ecall
  addi t5, a0, 0
  
  beq t5, zero, select_binary_decimal
  li a7, 51
  la a0, temperature_prompt
  ecall
  
  addi t1, a0, 0
  beq zero, zero, input_request
  
select_binary_decimal:
  li a7, 51
  la a0, binary_decimal_prompt
  ecall
  
  addi t1, a0, 0
  
input_request:
  li a7, 51
  la a0, input_prompt
  ecall
  
  addi a1, t1, 0
  
  beq t5, zero, execute_binary_decimal_conversion
  jal ra, temperature_conversion
  beq zero, zero, show_output
  
execute_binary_decimal_conversion:
  jal ra, binary_decimal_conversion

# Display result
show_output:
  addi a1, a0, 0 # store result  
  li a7, 56
  la a0, output_message
  ecall
  
  li a7, 51
  la a0, retry_prompt
  ecall
  
  beq a0, zero, main_loop
  
  li a7, 10
  ecall
