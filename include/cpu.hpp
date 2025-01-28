#ifndef _CPU_HPP_
#define _CPU_HPP_

#include "mem.hpp"

// CPU 6502
class cpu
{   
public:
  enum flag {
    N = 0, V, Unuse, B, D, I, Z, C
  };

  cpu();
  ~cpu();

  void set_flag(flag f, u8 val);
  u8 get_flag(flag f);

private:
  void init();

  void opcode_handle(u8 opcode);
  
  void update_flags_reg(u8 reg);

  u16 prog_counter;
  u8 stack_pointer;
  u8 accum;
  u8 index_X;
  u8 index_Y;
  u8 status_register;

  // instructions
  static constexpr u8
  INS_NOP = 0xEA,			// no operation

  INS_TAX = 0xAA,			// transfer A to X
  INS_TXA = 0x8A,			// transfer X to A
  INS_DEX = 0xCA,			// decrement X
  INS_INX = 0xE8,			// increment X
  INS_TAY = 0xA8,			// transfer Y to A
  INS_TYA = 0x98,			// transfer A to Y
  INS_DEY = 0x88,			// decrement Y
  INS_INY = 0xC8,			// increment Y
  
  INS_ASL_A = 0x0A,		// arithmetic shift left A value
  INS_ASL_ZP = 0x06,		// arithmetic shift left value (from ZeroPage (8-bit) address)
  INS_ASL_ZPX = 0x16,		// arithmetic shift left value (from ZeroPage (8-bit) address + value X )
  INS_ASL_ABS = 0x0E,		// arithmetic shift left value (from absolute address)
  INS_ASL_ABSX = 0x1E,	// arithmetic shift left value (from absolute address + value X)

  INS_LSR_A = 0x4A,		// logical shift right A value
  INS_LSR_ZP = 0x46,		// logical shift right value (from ZeroPage (8-bit) address)
  INS_LSR_ZPX = 0x56,		// logical shift right value (from ZeroPage (8-bit) address + value X )
  INS_LSR_ABS = 0x4E,		// logical shift right value (from absolute address)
  INS_LSR_ABSX = 0x5E,	// logical shift right value (from absolute address + value X)

  INS_ROR_A = 0x6A,		// rotate left A value
  INS_ROR_ZP = 0x66,		// rotate left value (from ZeroPage (8-bit) address)
  INS_ROR_ZPX = 0x76,		// rotate left value (from ZeroPage (8-bit) address + value X )
  INS_ROR_ABS = 0x6E,		// rotate left value (from absolute address)
  INS_ROR_ABSX = 0x7E,	// rotate left value (from absolute address + value X)

  INS_ROL_A = 0x2A,		// rotate right A value
  INS_ROL_ZP = 0x26,		// rotate right value (from ZeroPage (8-bit) address)
  INS_ROL_ZPX = 0x36,		// rotate right value (from ZeroPage (8-bit) address + value X )
  INS_ROL_ABS = 0x2E,		// rotate right value (from absolute address)
  INS_ROL_ABSX = 0x3E,	// rotate right value (from absolute address + value X)

  INS_CMP_IM = 0xC9,		// compare A and value
  INS_CMP_ZP = 0xC5,		// compare A and (from ZeroPage (8-bit) address)
  INS_CMP_ZPX = 0xD5,		// compare A and (from ZeroPage (8-bit) address + value X )
  INS_CMP_ABS = 0xCD,		// compare A and (from absolute address)
  INS_CMP_ABSX = 0xDD,	// compare A and (from absolute address + value X)
  INS_CMP_ABSY = 0xD9,	// compare A and (from absolute address + value Y)
  INS_CMP_INDX = 0xC1,	// compare A and from address -> (from absolute address + value X)
  INS_CMP_INDY = 0xD1,	// compare A and from address -> (from absolute address + value Y)

  INS_CPX_IM = 0xE0,		// compare X and value
  INS_CPX_ZP = 0xE4,		// compare X and (from ZeroPage (8-bit) address)
  INS_CPX_ABS = 0xEC,		// compare X and (from absolute address)

  INS_CPY_IM = 0xC0,		// compare Y and value
  INS_CPY_ZP = 0xC4,		// compare Y and (from ZeroPage (8-bit) address)
  INS_CPY_ABS = 0xCC,		// compare Y and (from absolute address)

  INS_ADC_IM = 0x69,		// add with carry A and value
  INS_ADC_ZP = 0x65,		// add with carry A and (from ZeroPage (8-bit) address)
  INS_ADC_ZPX = 0x75,		// add with carry A	and (from ZeroPage (8-bit) address + value X )
  INS_ADC_ABS = 0x6D,		// add with carry A	and (from absolute address)
  INS_ADC_ABSX = 0x7D,	// add with carry A	and (from absolute address + value X)
  INS_ADC_ABSY = 0x79,	// add with carry A	and (from absolute address + value Y)
  INS_ADC_INDX = 0x61,	// add with carry A	and from address -> (from absolute address + value X)
  INS_ADC_INDY = 0x71,	// add with carry A	and from address -> (from absolute address + value Y)

  INS_SBC_IM = 0xE9,		// substract with carry A and value
  INS_SBC_ZP = 0xE5,		// substract with carry A and (from ZeroPage (8-bit) address)
  INS_SBC_ZPX = 0xF5,		// substract with carry A and (from ZeroPage (8-bit) address + value X )
  INS_SBC_ABS = 0xED,		// substract with carry A and (from absolute address)
  INS_SBC_ABSX = 0xFD,	// substract with carry A and (from absolute address + value X)
  INS_SBC_ABSY = 0xF9,	// substract with carry A and (from absolute address + value Y)
  INS_SBC_INDX = 0xE1,	// substract with carry A and from address -> (from absolute address + value X)
  INS_SBC_INDY = 0xF1,	// substract with carry A and from address -> (from absolute address + value Y)

  INS_AND_IM = 0x29,		// logical A and value
  INS_AND_ZP = 0x25,		// logical A and from (ZeroPage (8-bit) address)
  INS_AND_ZPX = 0x35,		// logical A and from (ZeroPage (8-bit) address + value X)
  INS_AND_ABS = 0x2D,		// logical A and from (absolute address)
  INS_AND_ABSX = 0x3D,	// logical A and from (absolute address + value X)
  INS_AND_ABSY = 0x39,	// logical A and from (absolute address + value Y)
  INS_AND_INDX = 0x21,	// logical A and from from address -> (absolute address + value X)
  INS_AND_INDY = 0x31,	// logical A and from from address -> (absolute address + value Y)

  INS_ORA_IM = 0x09,		// logical A or value
  INS_ORA_ZP = 0x05,		// logical A or from (ZeroPage (8-bit) address)
  INS_ORA_ZPX = 0x15,		// logical A or from (ZeroPage (8-bit) address + value X)
  INS_ORA_ABS = 0x0D,		// logical A or from (absolute address)
  INS_ORA_ABSX = 0x1D,	// logical A or from (absolute address + value X)
  INS_ORA_ABSY = 0x19,	// logical A or from (absolute address + value Y)
  INS_ORA_INDX = 0x01,	// logical A or from from address -> (absolute address + value X)
  INS_ORA_INDY = 0x11,	// logical A or from from address -> (absolute address + value Y)

  INS_EOR_IM = 0x49,		// logical A exclusive or value
  INS_EOR_ZP = 0x45,		// logical A exclusive or from (ZeroPage (8-bit) address)
  INS_EOR_ZPX = 0x55,		// logical A exclusive or from (ZeroPage (8-bit) address + value X)
  INS_EOR_ABS = 0x4D,		// logical A exclusive or from (absolute address)
  INS_EOR_ABSX = 0x5D,	// logical A exclusive or from (absolute address + value X)
  INS_EOR_ABSY = 0x59,	// logical A exclusive or from (absolute address + value Y)
  INS_EOR_INDX = 0x41,	// logical A exclusive or from from address -> (absolute address + value X)
  INS_EOR_INDY = 0x51,	// logical A exclusive or from from address -> (absolute address + value Y)

  INS_STA_ZP = 0x85,		// store value from A to (ZeroPage (8-bit) address)
  INS_STA_ZPX = 0x95,		// store value from A to (ZeroPage (8-bit) address + value X)
  INS_STA_ABS = 0x8D,		// store value from A to (absolute address)
  INS_STA_ABSX = 0x9D,	// store value from A to (absolute address + value X)
  INS_STA_ABSY = 0x99,	// store value from A to (absolute address + value Y)
  INS_STA_INDX = 0x81,	// store value from A to address from -> (absolute address + value X)
  INS_STA_INDY = 0x91,	// store value from A to address from -> (absolute address + value Y)

  INS_STX_ZP = 0x86,		// store value from X to (ZeroPage (8-bit) address)
  INS_STX_ZPY = 0x96,		// store value from X to (ZeroPage (8-bit) address + value Y)
  INS_STX_ABS = 0x8E,		// store value from X to (absolute address)

  INS_STY_ZP = 0x84,		// store value from Y to (ZeroPage (8-bit) address)
  INS_STY_ZPX = 0x94,		// store value from Y to (ZeroPage (8-bit) address + value X)
  INS_STY_ABS = 0x8C,		// store value from Y to (absolute address)

  INS_LDA_IM = 0xA9,		// set value A
  INS_LDA_ZP = 0xA5,		// set value A (from ZeroPage (8-bit) address)
  INS_LDA_ZPX = 0xB5,		// set value A (from ZeroPage (8-bit) address + value X )
  INS_LDA_ABS = 0xAD,		// set value A (from absolute address)
  INS_LDA_ABSX = 0xBD,	// set value A (from absolute address + value X)
  INS_LDA_ABSY = 0xB9,	// set value A (from absolute address + value Y)
  INS_LDA_INDX = 0xA1,	// set value A from address -> (from absolute address + value X)
  INS_LDA_INDY = 0xB1,	// set value A from address -> (from absolute address + value Y)

  INS_LDX_IM = 0xA2,		// set value X
  INS_LDX_ZP = 0xA6,		// set value X from (ZeroPage (8-bit) address)
  INS_LDX_ZPY = 0xB6,		// set value X from (ZeroPage (8-bit) address + value Y)
  INS_LDX_ABS = 0xAE,		// set value X from (absolute address)
  INS_LDX_ABSY = 0xBE,	// set value X from (absolute address + value Y)

  INS_LDY_IM = 0xA0,		// set value Y
  INS_LDY_ZP = 0xA4,		// set value Y from (ZeroPage (8-bit) address)
  INS_LDY_ZPX = 0xB4,		// set value Y from (ZeroPage (8-bit) address + value X)
  INS_LDY_ABS = 0xAC,		// set value Y from (absolute address)
  INS_LDY_ABSX = 0xBC,	// set value Y from (absolute address + value X)

  INS_DEC_ZP = 0xC6,		// decrement value from (ZeroPage (8-bit) address)
  INS_DEC_ZPX = 0xD6,		// decrement value from (ZeroPage (8-bit) address + value X)
  INS_DEC_ABS = 0xCE,		// decrement value from (absolute address)
  INS_DEC_ABSX = 0xDE,	// decrement value from (absolute address + value X)

  INS_INC_ZP = 0xE6,		// increment value from (ZeroPage (8-bit) address)
  INS_INC_ZPX = 0xF6,		// increment value from (ZeroPage (8-bit) address + value X)
  INS_INC_ABS = 0xEE,		// increment value from (absolute address)
  INS_INC_ABSX = 0xFE,	// increment value from (absolute address + value X)

  INS_BEQ = 0xF0,			// branch if Zero flag true
  INS_BNE = 0xD0,			// branch if Zero flag false
  INS_BCS = 0xB0,			// branch if Carry flag true
  INS_BCC = 0x90,			// branch if Carry flag false
  INS_BMI = 0x30,			// branch if minus
  INS_BPL = 0x10,			// branch if plus
  INS_BVC = 0x50,			// branch if Overflow flag false
  INS_BVS = 0x70,			// branch if Overflow flag true

  INS_SEC = 0x38,			// set Carry flag
  INS_SED = 0xF8,			// set Decimal flag
  INS_SEI = 0x78,			// set Interrupt disable flag

  INS_CLC = 0x18,			// clear Carry flag
  INS_CLD = 0xD8,			// clear Decimal flag
  INS_CLV = 0xB8,			// clear Overflow flag
  INS_CLI = 0x58,			// clear Interrupt disable flag

  INS_TXS = 0x9A,			// transfer X to stack pointer
  INS_TSX = 0xBA,			// transfer stack pointer to X
  INS_PHA = 0x48,			// push accumulator to stack
  INS_PLA = 0x68,			// pull accumulator from stack
  INS_PHP = 0x08,			// push status register to stack
  INS_PLP = 0x28,			// pull status register from stack

  INS_JMP_ABS = 0x4C,	// jump to address
  INS_JMP_IND = 0x6C,	// jump to address indirect
  INS_JSR = 0x20,			// jump to subroutine 
  INS_RTS = 0x60,			// return from subroutine
  INS_RTI = 0x40,			// return from interrupt

  INS_BIT_ZP = 0x24,	// accumulator & memory, not set accumulator unlike AND
  INS_BIT_ABS = 0x2C,	// accumulator & memory, not set accumulator unlike AND

  INS_BRK = 0x00;			// software IRQ
  
};

#endif // _CPU_HPP_