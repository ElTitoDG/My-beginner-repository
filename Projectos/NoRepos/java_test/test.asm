start:     addi x5, x0, 10 # Initialize x5 with 10
loop:      sub x5, x5, x1 # Decrement x5
bnez       x5, loop # If x5 is not zero, go to loop
done:      nop # No operation
