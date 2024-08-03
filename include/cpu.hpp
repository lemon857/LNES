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
    LDA_IMM = 0xA9, LDA_ZP = 0xA5, LDA_ZPX = 0xB5, LDA_IZX = 0xA1, LDA_IZY = 0xB1, LDA_ABS = 0xAD, LDA_ABX = 0xBD, LDA_ABY = 0xB9,
                    STA_ZP = 0x85, STA_ZPX = 0x95, STA_IZX = 0x81, STA_IZY = 0x91, STA_ABS = 0x8D, STA_ABX = 0x9D, STA_ABY = 0x99,
    LDX_IMM = 0xA2, LDX_ZP = 0xA6, LDX_ZPY = 0xB6,                                 LDX_ABS = 0xAE,                 LDX_ABY = 0xBE,
                    STX_ZP = 0x86, STX_ZPY = 0x96,                                 STX_ABS = 0x8E,
    LDY_IMM = 0xA0, LDY_ZP = 0xA4, LDY_ZPX = 0xB4,                                 LDY_ABS = 0xAC, LDX_ABX = 0xBC,
                    STY_ZP = 0x86, STY_ZPY = 0x94,                                 STY_ABS = 0x8C,
    CPX_IMM = 0xE0, CPX_ZP = 0xE4,                                                 CPX_ABS = 0xEC,
    CPY_IMM = 0xC0, CPY_ZP = 0xC4,                                                 CPY_ABS = 0xCC,
                    DEC_ZP = 0xC6, DEC_ZPX = 0xD6,                                 DEC_ABS = 0xCE, DEC_ABX = 0xDE,
                    INC_ZP = 0xE6, INC_ZPX = 0xF6,                                 INC_ABS = 0xEE, INC_ABX = 0xFE,
    DEX_IMP = 0xCA, DEY_IMP = 0x88, INX_IMP = 0xE8, INY_IMP = 0xC8, TAX_IMP = 0xAA, TXA_IMP = 0x8A, TAY_IMP = 0xA8, TYA_IMP = 0x98, 
    TSX_IMP = 0xBA, TXS_IMP = 0x9A, PLA_IMP = 0x68, PHA_IMP = 0x48, PLP_IMP = 0x28, PHP_IMP = 0x08, BRK_IMP = 0x00, RTI_IMP = 0x40, 
    RTS_IMP = 0x60, CLC_IMP = 0x18, SEC_IMP = 0x38, CLD_IMP = 0xD8, SED_IMP = 0xF8, CLI_IMP = 0x58, SEI_IMP = 0x78, CLV_IMP = 0xB8, NOP_IMP = 0xEA, 
    ASL_IMP = 0x0A, ASL_ZP = 0x06, ASL_ZPX = 0x16,                                 ASL_ABS = 0x0E, ASL_ABX = 0x1E,
    ROL_IMP = 0x2A, ROL_ZP = 0x26, ROL_ZPX = 0x36,                                 ROL_ABS = 0x2E, ROL_ABX = 0x3E,
    LSR_IMP = 0x4A, LSR_ZP = 0x46, LSR_ZPX = 0x56,                                 LSR_ABS = 0x4E, LSR_ABX = 0x5E,
    ASL_IMP = 0x0A, ASL_ZP = 0x06, ASL_ZPX = 0x16,                                 ASL_ABS = 0x0E, ASL_ABX = 0x1E,
    JSR_ABS = 0x20, JMP_ABS = 0x4C, JMP_IND = 0x6C, BIT_ZP = 0x24, BIT_ABS = 0x2C, BPL_REL = 0x10, BMI_REL = 0x30, BVC_REL = 0x50, BVS_REL = 0x70,
    BCC_REL = 0x90, BCS_REL = 0xB0, BNE_REL = 0xD0, BEQ_REL = 0xF0,
    
    ;
};

#endif // _CPU_HPP_