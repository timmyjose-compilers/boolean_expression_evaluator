#pragma once

#ifndef _PARSER_H_
#define _PARSER_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "ast.h"

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
  void destroy_scanner(Scanner*);
  LinkedList *scan(Scanner*);

  typedef struct {
    Scanner *scanner;
  } Parser;

  Parser *init_parser(const char*);
  void destroy_parser(Parser*);
  Expression *parse(Parser*);

#ifdef __cplusplus
}
#endif
#endif
