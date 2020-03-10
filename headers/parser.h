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
