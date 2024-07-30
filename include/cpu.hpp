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
    u16 ProgCounter;
    u16 StackPointer;
    u8 Accum;
    u8 IndX;
    u8 IndY;
    u8 StatusReg;
};

#endif // _CPU_HPP_