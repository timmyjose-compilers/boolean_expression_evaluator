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
#include "memory.h"
#include "ast.h"

 typedef struct {
   LinkedList *tokens;
  } Parser;

  Parser *init_parser(LinkedList*);
  void destroy_parser(Parser*);
  Expression *parser_parse(Parser*);

#ifdef __cplusplus
}
#endif
#endif
