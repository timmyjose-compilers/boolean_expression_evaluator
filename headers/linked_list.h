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

  typedef struct Node {
    char *data;
    struct Node *prev;
    struct Node *next;
  } Node;

  typedef struct LinkedList {
    Node *head;
    Node *tail;
  } LinkedList;

  LinkedList *ll_init();
  void ll_destroy(LinkedList*);
  void ll_push_front(LinkedList*, char*);
  void ll_push_back(LinkedList*, char*);
  char *ll_pop_front(LinkedList*);
  char *ll_pop_back(LinkedList*);
  bool ll_is_empty(const LinkedList*);
  void ll_print(const LinkedList*);

#ifdef __cplusplus
}
#endif
#endif