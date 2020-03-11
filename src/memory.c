#include "../headers/memory.h"

void *allocate(const size_t sz)
{
  void *block = malloc(sz);

  if (block == NULL) {
    fprintf(stderr, "Could not allocate memory for block - allocator returned NULL\n");
    exit(-1);
  }

  return block;
}
