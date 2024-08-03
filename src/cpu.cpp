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

u8 cpu::get_byte(u16 addr)
{
    return bus::read(addr);
}
void cpu::set_byte(u16 addr, u8 value)
{
    bus::write(addr, value);
}
u8 cpu::fetch_byte()
{  
    u8 val = bus::read(prog_counter);
    prog_counter++;
    return val;
}
void cpu::update_flags_reg(u8 reg)
{
    set_flag(Z, reg == 0);
    set_flag(N, (reg & 0b10000000) >> 7);
}

void cpu::opcode_handle(u8 opcode)
{
    switch (opcode)
    {
    
    default:
        break;
    }
}