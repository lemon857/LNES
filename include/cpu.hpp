#ifndef _CPU_HPP_
#define _CPU_HPP_

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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

    u16 prog_counter;
    u16 stack_pointer;
    u8 accum;
    u8 index_X;
    u8 index_Y;
    u8 status_register;
};

#endif // _CPU_HPP_