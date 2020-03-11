#pragma once

#ifndef _CHAR_BUFFER_H_
#define _CHAR_BUFFER_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "memory.h"

  typedef struct {
    char *buffer;
    size_t len;
    size_t cap;
  } CharBuffer;

  CharBuffer *init_cb();
  void destroy_cb(CharBuffer*);

  void cb_push_back(CharBuffer*, char);
  void cb_push_front(CharBuffer*, char);
  char cb_pop_back(CharBuffer*);
  char cb_pop_front(CharBuffer*);
  size_t cb_len(CharBuffer*);
  size_t cb_cap(CharBuffer*);
  bool cb_is_empty(CharBuffer*);

#ifdef __cplusplus
}
#endif
#endif

