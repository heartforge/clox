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

  // Write 1 byte constant and write it to the Chunk with the operand
  constant = addConstant(&chunk, 3.4);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  // Write bytecode op for addition.
  writeChunk(&chunk, OP_ADD, 123);

  constant = addConstant(&chunk, 5.6);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  writeChunk(&chunk, OP_DIVIDE, 123);
  writeChunk(&chunk, OP_NEGATE, 123);

  // Return using OP_RETURN.
  writeChunk(&chunk, OP_RETURN, 123);

  disassembleChunk(&chunk, "test chunk");
  interpret(&chunk);
  freeVM();
  freeChunk(&chunk);
  return 0;
}
