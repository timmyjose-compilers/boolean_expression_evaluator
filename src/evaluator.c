#include "../headers/evaluator.h"

Token *init_token(const char *name, const char *spelling)
{
  Token *token = malloc(sizeof(Token));
  if (token == NULL) {
    fprintf(stderr, "Could not create token - allocator returned NULL.\n");
    exit(-1);
  }

  token->name = malloc(sizeof(char) * strlen(name));
  strncpy(token->name, name, strlen(name));

  token->spelling = malloc(sizeof(char) * strlen(name));
  strncpy(token->spelling, spelling, strlen(spelling));

  return token;
}

