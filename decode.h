/*  

@file decode.h

@brief Header file for class decode

Copyright © 2020 Michael Ranasinghe

*/

class decode 
{       

    public:

        /// @brief constructor
        decode(void) 
        {
        };

        /// @brief destructor
        ~decode(void) 
        {
        };


        /// @brief Translates MIPS 32 bit instruction into assembly
        /// @param mipsinstruction1 32 bit binary instruction
        /// @param programcounter Current instruction address being executed
        /// into assembly
        void binarytoassembly(unsigned int mipsinstruction, int programcounter);
    
    private:
        //* BITMASKS below, assuming arithemetic operation for maskreg3, and maskreg4
        int maskopcode; //op code

        //instruction field register
        int maskreg1;
        int maskreg2;
        int maskreg3;
        int maskreg4;

        //instruction offset
        int maskoffset;

};