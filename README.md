# clox

### Execution
`clang -o main main.c chunk.c memory.c debug.c value.c`

### Instructions
Instructions are represent:wed by bytecode in a struct called Chunk.

### Constants
All constants are stored together in a section of memory. Each chunk will carry with it a list of the values that appear as literals in the program.

### Resered Keywords
Reserved keyword identification is implemented using tries and state machines.
