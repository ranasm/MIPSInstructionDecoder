# MIPSInstructionDecoder

This project is a disassembler for basic MIPS instructions. That is, the input will be the 32-bit machine instructions that a compiler or assembler produces. The program then figures out what the original source instructions were that created those 32-bit machine instructions and outputs them. The possible source instructions that can be disassembled are: add, sub, and, or, slt, lw, sw, beq, bne. This project ignores all other MIPS instructions.

## Instructions to Run

Clone this repository (MIPSInstructionDecoder) to your local desktop. From the command line, change into this cloned repository directory, and run the "build.sh" script. This will create an executable named "MIPS_Instruction_Decoder". Run this executable to output decoded MIPS instructions. 

## Adding New MIPS Instructions 

If you would like to add any additional machine instructions, simply open the main.cpp file and add the instruction to the current list of available instructions. Make sure to call the newly added instruction as appropriate. 

For example, if you added an instruction as follows: 
    "unsigned int instruction11= 0x8ECDFFF0; // 0b10001110110011011111111111110000", 
then you would have to add the line:
"InstructionDecoder.binarytoassembly(instruction11,pc)"
