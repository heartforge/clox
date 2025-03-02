#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "vm.h"

int main(int argc, char *argv[]) {
  initVM();

  Chunk chunk;
  initChunk(&chunk);

  // Write 1 byte constant using OP_CONSTANT opcode.
  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  // Write 3 byte constant using OP_CONSTANT_LONG opcode.
  writeChunk(&chunk, OP_CONSTANT_LONG, 123);
  writeConstant(&chunk, 123456789, 123);

  // Return using OP_RETURN.
  writeChunk(&chunk, OP_RETURN, 123);

  disassembleChunk(&chunk, "test chunk");
  interpret(&chunk);
  freeVM();
  freeChunk(&chunk);
  return 0;
}
