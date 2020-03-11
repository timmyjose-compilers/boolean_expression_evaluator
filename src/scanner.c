#include "../headers/scanner.h"

Token *init_token(const char *name, const char *spelling)
{
  Token *token = malloc(sizeof(Token));

  if (token == NULL) {
    fprintf(stderr, "Could not create token - allocator returned NULL.\n");
    exit(-1);
  }

  token->name = malloc(sizeof(char) * strlen(name));
  strncpy(token->name, name, strlen(name));

  token->spelling = malloc(sizeof(char) * strlen(spelling));
  strncpy(token->spelling, spelling, strlen(spelling));

  return token;
}

void destroy_token(Token *token)
{
  if (token) {
    if (token->name) free(token->name);
    if (token->spelling) free(token->spelling);
    free(token);
  }
}

struct LinkedList *scan()
{
  return NULL;

}
