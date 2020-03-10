#pragma once

#ifndef _EVALUATOR_H_
#define _EVALUATOR_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "parser.h"

  typedef struct {
     Parser *parser;
  } Evaluator;

  Evaluator *init_evaluator(const char*);
  void destroy_evaluator(Evaluator*);
  bool evaluate(Evaluator*);

#ifdef __cplusplus
}
#endif
#endif
