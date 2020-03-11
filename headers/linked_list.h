#pragma once

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "scanner.h"
#include "memory.h"

  typedef struct Node {
    void *data;
    struct Node *prev;
    struct Node *next;
  } Node;

  typedef struct LinkedList {
    Node *head;
    Node *tail;
  } LinkedList;

  LinkedList *ll_init();
  void ll_destroy(LinkedList*);

  bool ll_is_empty(const LinkedList*);
  void ll_print_int(const LinkedList*);
  void ll_print_string(const LinkedList*);
  void ll_print_token(const LinkedList*);

  void ll_push_back_int(LinkedList*, int);
  void ll_push_front_int(LinkedList*, int);
  int ll_pop_back_int(LinkedList*);
  int ll_pop_front_int(LinkedList*);

  void ll_push_back_string(LinkedList*, const char*);
  void ll_push_front_string(LinkedList*, const char*);
  const char *ll_pop_back_string(LinkedList *);
  const char *ll_pop_front_string(LinkedList *);

  void ll_push_back_token(LinkedList*, Token*);
  void ll_push_front_token(LinkedList*, Token*);
  Token *ll_pop_back_token(LinkedList *);
  Token *ll_pop_front_token(LinkedList *);

#ifdef __cplusplus
}
#endif
#endif