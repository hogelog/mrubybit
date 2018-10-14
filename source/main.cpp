#include "MicroBit.h"

#define MRBC_SRC_CONSOLE_H_
void console_printf(const char *fstr, ...);
#include "mrubyc.h"

#define MRUBY_MEMORY_SIZE (1024 * 10)

MicroBit uBit;
static uint8_t memory_pool[MRUBY_MEMORY_SIZE];

struct VM * init_mruby() {
  //mrbc_init_alloc(memory_pool, MRUBY_MEMORY_SIZE);
  //mrbc_init_global();
  //mrbc_init_class();
  return mrbc_vm_open(NULL);
}

int main() {
  uBit.init();

  init_mruby();

  uBit.display.scroll("HELLO WORLD! :)");
  release_fiber();
}
