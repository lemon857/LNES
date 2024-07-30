#ifndef _CPU_HPP_
#define _CPU_HPP_

#include "mem.hpp"

// CPU 6502
class cpu
{   
public:
    enum flag
    {
        N = 0, V, Unuse, B, D, I, Z, C
    };

    cpu();
    ~cpu();

    void set_flag(flag f, u8 val);
    u8 get_flag(flag f);

private:
    void init();

    void opcode_handle(u8 opcode);

    u16 prog_counter;
    u16 stack_pointer;
    u8 accum;
    u8 index_X;
    u8 index_Y;
    u8 status_register;

    // instructions
    static constexpr u8     
    ORA_IMM = 0x09, ORA_ZP = 0x05, ORA_ZPX = 0x15, ORA_IZX = 0x01, ORA_IZY = 0x11, ORA_ABS = 0x0D, ORA_ABX = 0x1D, ORA_ABY = 0x19,
    AND_IMM = 0x29, AND_ZP = 0x25, AND_ZPX = 0x35, AND_IZX = 0x21, AND_IZY = 0x31, AND_ABS = 0x2D, AND_ABX = 0x3D, AND_ABY = 0x39,
    EOR_IMM = 0x49, EOR_ZP = 0x45, EOR_ZPX = 0x55, EOR_IZX = 0x41, EOR_IZY = 0x51, EOR_ABS = 0x4D, EOR_ABX = 0x5D, EOR_ABY = 0x59,
    ADC_IMM = 0x69, ADC_ZP = 0x65, ADC_ZPX = 0x75, ADC_IZX = 0x61, ADC_IZY = 0x71, ADC_ABS = 0x6D, ADC_ABX = 0x7D, ADC_ABY = 0x79,
    SBC_IMM = 0xE9, SBC_ZP = 0xE5, SBC_ZPX = 0xF5, SBC_IZX = 0xE1, SBC_IZY = 0xF1, SBC_ABS = 0xED, SBC_ABX = 0xFD, SBC_ABY = 0xF9,
    CMP_IMM = 0xC9, CMP_ZP = 0xC5, CPM_ZPX = 0xD5, CMP_IZX = 0xC1, CMP_IZY = 0xD1, CMP_ABS = 0xCD, CPM_ABX = 0xDD, CMP_ABY = 0xD9,
    ;
};

#endif // _CPU_HPP_