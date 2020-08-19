/*  

@file main.cpp

@brief ComputerArchitecture: Project 1-MIPS Dissembler
Creates corresponding assembly instructions from input value
Valid instruction types: add, sub, and, or, slt, lw, sw, beq, bne

Copyright © 2020 Michael Ranasinghe

*/


#include <iostream>  // provides access to procedures for keyboard input/output
#include <iomanip>     // provides formatting facilities for outputs
#include <cmath>   // provides lots of entry-level math functions
#include <cstdlib>     // provides definitions of numeric limits
#include <cstring> // provides entry-level string handling functions
#include <list>
#include "decode.h"

using namespace std;


int main()
{

	//*****************************************
	//  Place MIPS Instructions here to decode
	//*****************************************

	unsigned int instruction1= 0x032BA020; // 0b00000011001010111010000000100000;
	unsigned int instruction2= 0x8CE90014; // 0b10001100111010010000000000010100;
	unsigned int instruction3= 0x12A90003; // 0b00010010101010010000000000000011;
	unsigned int instruction4= 0x022DA822; // 0b00000010001011011010100000100010;
	unsigned int instruction5= 0xADB30020; // 0b10101101101100110000000000100000;
	unsigned int instruction6= 0x02697824; // 0b00000010011010010111100000100100;
	unsigned int instruction7= 0xAE8FFFF4; // 0b10101110100011111111111111110100;
	unsigned int instruction8= 0x018C6020; // 0b00000001100011000110000000100000;
	unsigned int instruction9= 0x02A4A825; // 0b00000010101001001010100000100101;
	unsigned int instruction10= 0x158FFFF7; // 0b00010101100011111111111111110111;
	unsigned int instruction11= 0x8ECDFFF0; // 0b10001110110011011111111111110000;

	//*****************************************

	// Initialize decoder here
	decode InstructionDecoder;
	
	int pc= 0x9a040;

	cout <<"Decoded Instructions:" << endl; 
	cout <<"---------------------- \n";

	InstructionDecoder.binarytoassembly(instruction1,pc);
	InstructionDecoder.binarytoassembly(instruction2,pc);
	InstructionDecoder.binarytoassembly(instruction3,pc);
	InstructionDecoder.binarytoassembly(instruction4,pc);
	InstructionDecoder.binarytoassembly(instruction5,pc);
	InstructionDecoder.binarytoassembly(instruction6,pc);
	InstructionDecoder.binarytoassembly(instruction7,pc);
	InstructionDecoder.binarytoassembly(instruction8,pc);
	InstructionDecoder.binarytoassembly(instruction9,pc);
	InstructionDecoder.binarytoassembly(instruction10,pc);
	InstructionDecoder.binarytoassembly(instruction11,pc);

}


