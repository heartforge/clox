#include <stdlib.h>

#include "memory.h"

/*
 * Reallocates memory at pointer to resize it from the oldSize to the newSize.
 * If newSize == 0, memory is freed and NULL is returned.
 * Otherwise, reallocate will use realloc to attempt to resize it. If memory
 * blocks after the existing is free, it will take it and return the provided
 * pointer. Otherwise, it will allocaate memory at a different location and
 * return that new pointer.
 */
void *reallocate(void *pointer, size_t oldSize, size_t newSize) {
  if (newSize == 0) {
    free(pointer);
    return NULL;
  }

  void *result = realloc(pointer, newSize);
  if (result == NULL)
    exit(1); // If relloc fails, return err code 1;
  return result;
}
