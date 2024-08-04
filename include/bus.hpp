#ifndef _BUS_HPP_
#define _BUS_HPP_

#include "mem.hpp"

class bus
{
public:
    bus() = delete;
    bus(bus&&) = delete;
    bus operator=(bus&&) = delete;
    ~bus() = delete;

    static void write(u16 addr, u8 data);
    static u8 read(u16 addr);

    static void reset();
    static void insertCartridge();
private:
    static mem memory;
};

#endif // _BUS_HPP_