#include "cpu.hpp"

#include "bus.hpp"

cpu::cpu()
{
    init();
}

cpu::~cpu()
{

}

void cpu::set_flag(flag f, u8 val)
{
    val = val << (7 - static_cast<int>(f));
    status_register |= val;
}

u8 cpu::get_flag(flag f)
{   
    u8 tmp = status_register;
    tmp = tmp >> (7 - static_cast<int>(f));
    return tmp & 1;
}

void cpu::init()
{
    accum = index_X = index_Y = 0;
    status_register = 0;
    set_flag(Unuse, 1);
    prog_counter = 0xFFFC;
    stack_pointer = 0x0100;
}

void cpu::opcode_handle(u8 opcode)
{
    switch (opcode)
    {
    case ORA_IMM: {
        
    } break;
    
    default:
        break;
    }
}