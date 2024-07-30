#include "cpu.hpp"

void cpu::set_flag(flag f, u8 val)
{
    u8 tmp = 1;
    tmp << (7 - (u8)f);
    StatusReg |= tmp;
}

u8 cpu::get_flag(flag f)
{   
    u8 tmp = StatusReg;
    tmp >> (7 - (u8)f);
    return tmp & 1;
}