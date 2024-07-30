#ifndef _BUS_HPP_
#define _BUS_HPP_

#include "cpu.hpp"
#include "mem.hpp"

class bus
{
public:
    bus();
    ~bus();

    void write(u16 addr, u8 data);
    u8 read(u16 addr);

    void reset();
    void insertCartrige();
private:

};

#endif // _BUS_HPP_