# MIPSInstructionDecoder

This project is a disassembler for basic MIPS instructions. That is, the input will be the 32-bit machine instructions that a compiler or assembler produces. The program then figures out what the original source instructions were that created those 32-bit machine instructions and outputs them. The possible source instructions that can be disassembled are: add, sub, and, or, slt, lw, sw, beq, bne. This project ignores all other MIPS instructions.

## Instructions to Run

Clone this repository (MIPSInstructionDecoder) to your local desktop. Change into this cloned repository directory, and run the "build.sh" script from the command line. This will create an executable named "MIPS_Instruction_Decoder". Run this executable to output decoded MIPS instructions. 

