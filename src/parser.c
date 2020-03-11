#include "../headers/parser.h"

Parser *init_parser(LinkedList *tokens)
{
  Parser *parser = allocate(sizeof(Parser));
  parser->tokens = tokens;

  return parser;
}

void destroy_parser(Parser *parser)
{
  if (parser) {
    if (parser->tokens) ll_destroy(parser->tokens);
    free(parser);
  }
}

Expression *parser_parse(Parser *parser)
{
  return NULL;
}
