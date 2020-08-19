#Run this bash script to create executable
g++ -g decode.cpp -c -o decode.o
g++ -g main.cpp -c -o main.o
g++ -o MIPS_Instruction_Decoder main.o decode.o -lm

