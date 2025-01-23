#ifndef _MEM_HPP_
#define _MEM_HPP_

using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;

struct mem {
  u8 data[0xFFFF];
  void init() {
    for (u16 i = 0; i < 0xFFFF; i++) data[i] = 0;
  }
  u8 operator[](u16 index) const {
    return data[index];
  }
  u8& operator[](u16 index) {
    return data[index];    
  }
};


#endif // _MEM_HPP_