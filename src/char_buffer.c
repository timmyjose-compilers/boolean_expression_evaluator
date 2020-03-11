#include "../headers/char_buffer.h"

CharBuffer *init_cb()
{
  CharBuffer *cb = allocate(sizeof(CharBuffer));
  cb->buffer = allocate(sizeof(char));
  cb->len = 0;
  cb->cap = 1;

  return cb;
}

void destroy_cb(CharBuffer *cb)
{
  if (cb) {
    if (cb->buffer) free(cb->buffer);
    free(cb);
  }
}

void cb_push_back(CharBuffer *cb, char c)
{
  if (cb->len == cb->cap) {
    char *newbuf = callocate(cb->cap * 2);
    
    for (int i = 0; i < cb->len; i++)
      newbuf[i] = cb->buffer[i];

    free(cb->buffer);
    cb->buffer = newbuf;
    cb->cap *= 2;
  }

  cb->buffer[cb->len] = c;
  cb->len++;
}

void cb_push_front(CharBuffer *cb, char c)
{
  if (cb->len == cb->cap) {
    char *newbuf = callocate(cb->cap * 2);

    for (int i = 0; i < cb->len; i++)
      newbuf[i] = cb->buffer[i];

    free(cb->buffer);
    cb->buffer = newbuf;
    cb->cap *= 2;
  }

  cb->len++;
  for (int i = cb->len; i > 0; i--)
    cb->buffer[i] = cb->buffer[i-1];
  
  cb->buffer[0] = c;
}

char cb_pop_back(CharBuffer *cb)
{
  if (cb_is_empty(cb)) {
    fprintf(stderr, "Could not pop back char buffer - empty\n");
    exit(-2);
  }

  char c = cb->buffer[cb->len - 1];
  cb->len--;

  if (cb->len < cb->cap / 2) {
    char *newbuf = callocate(cb->cap / 2);

    for (int i = 0; i < cb->len; i++)
      newbuf[i] = cb->buffer[i];

    free(cb->buffer);
    cb->buffer = newbuf;
    cb->cap /= 2;
  }

  return c;
}

char cb_pop_front(CharBuffer *cb)
{
  if (cb_is_empty(cb)) {
    fprintf(stderr, "Could not pop front char buffer - empty\n");
    exit(-2);
  }

  char c = cb->buffer[0];
  
  for (int i = 0; i < cb->len - 1; i++) 
    cb->buffer[i] = cb->buffer[i+1];

  cb->len--;
  if (cb->len < cb->cap / 2) {
    char *newbuf = callocate(cb->cap / 2);

    for (int i = 0; i < cb->len; i++)
      newbuf[i] = cb->buffer[i];

    free(cb->buffer);
    cb->buffer = newbuf;
    cb->cap /= 2;
  }

  return c;
}

size_t cb_len(CharBuffer *cb) {
  return cb->len;
}

size_t cb_cap(CharBuffer *cb) {
  return cb->cap;
}

bool cb_is_empty(CharBuffer *cb)
{
  return cb->len == 0;
}

char *cb_copy(CharBuffer *cb) 
{
  char *buffer = allocate(sizeof(char) * strlen(cb->buffer));
  strncpy(buffer, cb->buffer, strlen(cb->buffer));

  return buffer;
}
