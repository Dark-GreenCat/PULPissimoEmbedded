.section .text
.global delay_us
delay_us:
    # a0 = (uint32_t) us
1: # Start of while 
    nop
    nop
    nop
    nop
    nop
    addi   a0, a0, -1    # us--
    beqz   a0, 1f        # if(us == 0) break
    j      1b            # Jump back to condition (1 backwards)

1: # End of while loop
    ret                  # Return back via the return address register  