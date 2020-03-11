#pragma once

#ifndef _SCANNER_H_
#define _SCANNER_H_
#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

  struct LinkedList;

  typedef enum {
    IDENTIFIER,
    BOOLEAN,
    OPERATOR
  } TokenType;

  typedef struct {
    char *name;
    char *spelling;
  } Token;

  Token *init_token(const char*, const char*);
  void destroy_token(Token*);

  typedef struct {
    char *data;
  } Scanner;

  Scanner *init_scanner(const char*);
  void destroy_scanner(const Scanner*);
  struct LinkedList *scan(Scanner*);

#ifdef __cplusplus
}
#endif
#endif

