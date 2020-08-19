/*  

@file decode.cpp

@brief Implementation for class decode

Copyright © 2020 Michael Ranasinghe

*/


#include <iostream>  // provides access to procedures for keyboard input/output
#include <iomanip>     // provides formatting facilities for outputs
#include <cmath>   // provides lots of entry-level math functions
#include <cstdlib>     // provides definitions of numeric limits
#include <cstring> // provides entry-level string handling functions
#include "decode.h"



void decode::binarytoassembly
    (
    	unsigned int mipsinstruction,
    	int programcounter
    )
{
	maskopcode=(0xfc000000>>26);
    maskreg1=(0x03e00000>>21);
    maskreg2=(0x001f0000>>16);
    maskreg3=(0x0000f800);
    maskreg4=(0x0000003f);
    maskoffset=(0x0000ffff);

	// @note: 
	// I Type Instruction bit format: 6/5/5/16 
	// R Type Instruction bit format: 6/5/5/5/5/6 


    int opcode= mipsinstruction>>26;
    int rs= mipsinstruction>>21;
    int rt= mipsinstruction>>16;

     //use bitmask to find value of register fields
    rs= (maskreg1 & rs);       
    rt= (maskreg2 & rt);       
    

    int instructiontype= maskopcode & opcode;

    switch(instructiontype) 
    {
    	case 0x0:  //Determining  opcode bits for add
    	{ 

    		int dest= (maskreg3 & mipsinstruction)>>11; 
        
        	if ((maskreg4 & mipsinstruction)== 0x20)    //determining whether add
        	{
            
            	std::cout  << std::hex<< programcounter <<"\t" << "add\t" << "$" << std::dec << dest << "\t" << "$" << std::dec <<  rs << "\t" << "$" <<std::dec <<  rt<< std::endl;
				break;
        	}
        	else if ((maskreg4 & mipsinstruction)== 0x22)   //else has to be subtract
        	{
            	std::cout  << std::hex << programcounter <<"\t" <<  "sub\t" << "$" << std::dec << dest << "\t" << "$" << std::dec << rs << "\t" << "$" << std::dec << rt<< std::endl;
				break;
        	}
        	else if ((maskreg4 & mipsinstruction)== 0x25)
        	{
            	std::cout  <<  std::hex << programcounter <<"\t" <<  "OR\t" << "$" << std::dec << dest << "\t" << "$" << std::dec << rs << "\t" << "$" << std::dec << rt<< std::endl;
				break;
			}
        	else if ((maskreg4 & mipsinstruction)== 0x24)
        	{
        	    std::cout  <<  std::hex << programcounter <<"\t" << "AND\t" << "$" << std::dec << dest << "\t" << "$" << std::dec << rs << "\t" << "$" <<std::dec <<  rt<< std::endl;
				break;
			}


    		}

    	case 0x23: // check condition if opcode represents load word
    	{
    		short offset= (maskoffset & mipsinstruction);
        	std::cout  << std::hex << programcounter <<"\t" << "lw\t" << "$" << std::dec << rt << ","<< offset<< "($"<< std::dec << rs << ")"<< std::endl;
			break;
    	}

    	case 0x2B: // check if opcode represents store word
    	{
    		short offset= (maskoffset & mipsinstruction);
        	std::cout  << std::hex << programcounter <<"\t" << "sw\t" << "$" <<std::dec <<  rt << ","<< offset<< "($"<< std::dec << rs << ")"<< std::endl;
			break;
    	}

    	case 0x4: // check if opcode represents beq
    	{
    		short pcreloffset= (maskoffset & mipsinstruction)<<2;
        	int four= 0x4;
        	int test= pcreloffset + four + programcounter;
        	std::cout<< std::hex << programcounter << "\t" << "BEQ\t" << "$" << std::dec <<  rs << ","<< "$" << std::dec << rt << ","<< "address" <<" " <<  std::dec << test << std::endl;
			break;
    	}

    	case 0x5: // check if opcode represents bne
    	{
			short pcreloffset= (maskoffset & mipsinstruction)<<2;
        	int four= 0x4;
        	int test= pcreloffset + four + programcounter;
        	// cout << hex << pcreloffset << endl;
        	std::cout<<  std::hex << programcounter << "\t" <<"BNE\t" << "$" <<std::dec <<  rs << ","<< "$" << std::dec << rt << ","<< "address" <<" " << std::dec << test << std::endl;
			break;
		}

    	default:
    	{
    		std::cout << "Could not properly decode I type or R type instruction" << std::endl; 
			break;
		}

    }


}
