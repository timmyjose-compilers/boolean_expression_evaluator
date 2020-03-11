#pragma once

#ifndef _SCANNER_H_
#define _SCANNER_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "char_buffer.h"

  struct LinkedList;
  struct LinkedList *ll_init();

  typedef enum {
    LPAREN,
    RPAREN,
    IDENTIFIER,
    BOOLEAN,
    OPERATOR
  } TokenType;

  typedef struct {
    TokenType kind;
    char *spelling;
  } Token;

  void ll_push_back_token(struct LinkedList*, Token*);

  Token *init_token(TokenType, const char*);
  void destroy_token(Token*);

  typedef struct {
    char *data;
  } Scanner;

  Scanner *init_scanner(const char*);
  void destroy_scanner(Scanner*);
  struct LinkedList *scanner_scan(Scanner*);

#ifdef __cplusplus
}
#endif
#endif

