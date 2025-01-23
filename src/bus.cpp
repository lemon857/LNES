#include "bus.hpp"

mem bus::memory;

void bus::write(u16 addr, u8 data) {
  memory[addr] = data;
}

u8 bus::read(u16 addr) {
  return memory[addr];
}

void bus::reset() {
  memory.init();
}
void bus::insertCartridge() {

}