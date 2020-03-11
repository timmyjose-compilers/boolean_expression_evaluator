#include "../headers/scanner.h"

/* Token Constructor */
Token *init_token(TokenType kind, const char *spelling)
{
  Token *token = malloc(sizeof(Token));

  if (token == NULL) {
    fprintf(stderr, "Could not create token - allocator returned NULL.\n");
    exit(-1);
  }

  token->kind = kind;

  token->spelling = malloc(sizeof(char) * strlen(spelling));
  strncpy(token->spelling, spelling, strlen(spelling));

  return token;
}

/* Token destructor */
void destroy_token(Token *token)
{
  if (token) {
    if (token->spelling) free(token->spelling);
    free(token);
  }
}

/* Scanner constructor */
Scanner *init_scanner(const char *s)
{
  Scanner *scanner = (Scanner*)allocate(sizeof(Scanner));
  scanner->data = allocate(sizeof(char) * strlen(s));
  strncpy(scanner->data, s, strlen(s));

  return scanner;
}

/* Scanner destructor */
void destroy_scanner(Scanner *scanner)
{
  if (scanner) {
    if (scanner->data) free(scanner->data);
    free(scanner);
  }
}

/* Scanning starts here - the output is a LinkedList of Token objects */
struct LinkedList *scanner_scan(Scanner *scanner)
{
  struct LinkedList *tokens = ll_init();

  int len = strlen((char *)scanner->data);
  int current = 0;

  while (current < len) {
    switch (scanner->data[current]) {
      case '(': 
        {
          Token *token = init_token(LPAREN, "(");
          ll_push_back_token(tokens, token);
          current++;
        }
        break;

      case ')': 
        {
          Token *token = init_token(RPAREN, ")");
          ll_push_back_token(tokens, token);
          current++;
        }
        break;

      case 'a':
      case 'b':
      case 'c':
      case 'd':
      case 'f':
      case 'g':
      case 'h':
      case 'i':
      case 'j':
      case 'k':
      case 'l':
      case 'm':
      case 'n':
      case 'o':
      case 'p':
      case 'q':
      case 'r':
      case 's':
      case 't':
      case 'u':
      case 'v':
      case 'w':
      case 'x':
      case 'y':
      case 'z':
      case 'A':
      case 'B':
      case 'C':
      case 'D':
      case 'F':
      case 'G':
      case 'H':
      case 'I':
      case 'J':
      case 'K':
      case 'L':
      case 'M':
      case 'N':
      case 'O':
      case 'P':
      case 'Q':
      case 'R':
      case 'S':
      case 'T':
      case 'U':
      case 'V':
      case 'W':
      case 'X':
      case 'Y':
      case 'Z': 
        {
          CharBuffer *cb = init_cb();

          while (isalpha(scanner->data[current])) {
            cb_push_back(cb, scanner->data[current++]);
          }

          ll_push_back_token(tokens, init_token(IDENTIFIER, cb_copy(cb)));

          destroy_cb(cb);
        } 
        break;

      case '-': 
        {
          CharBuffer *cb = init_cb();
          cb_push_back(cb, scanner->data[current++]);

          if (scanner->data[current] != '>') {
            fprintf(stderr, "[Scanner] expected character '>', found character '%c'\n", scanner->data[current]);
            exit(-3);
          }

          cb_push_back(cb, scanner->data[current++]);
          ll_push_back_token(tokens, init_token(OPERATOR, cb_copy(cb)));

          destroy_cb(cb);
        }
        break;

      case '!':
        {
          CharBuffer *cb = init_cb();
          cb_push_back(cb, scanner->data[current++]);

          ll_push_back_token(tokens, init_token(OPERATOR, cb_copy(cb)));

          destroy_cb(cb); 
        }
        break;

      case '&': 
        {
          CharBuffer *cb = init_cb();
          cb_push_back(cb, scanner->data[current]);

          if (scanner->data[++current] != '&') {
            fprintf(stderr, "[Scanner] expected character '&', found character '%c'\n", scanner->data[current]);
            exit(-3);
          }

          cb_push_back(cb, scanner->data[current++]);
          ll_push_back_token(tokens, init_token(OPERATOR, cb_copy(cb)));

          destroy_cb(cb);
        }
        break;
      case '|':
        {
          CharBuffer *cb = init_cb();
          cb_push_back(cb, scanner->data[current]);

          if (scanner->data[++current] != '|') {
            fprintf(stderr, "[Scanner] expected character '|', found character '%c'\n", scanner->data[current]);
            exit(-3);
          }

          cb_push_back(cb, scanner->data[current++]);
          ll_push_back_token(tokens, init_token(OPERATOR, cb_copy(cb)));

          destroy_cb(cb);
        }
        break;

      case '^':
        {
          CharBuffer *cb = init_cb();
          cb_push_back(cb, scanner->data[current++]);
          ll_push_back_token(tokens, init_token(OPERATOR, cb_copy(cb)));

          destroy_cb(cb);
        }
        break;

      case ' ':
      case '\t':
      case '\n':
        {
          while (isspace(scanner->data[current++])) 
            ;
          current--;
        }
        break;

      default: 
        {
          fprintf(stderr, "[Scanner] unexpected character found while scanning: '%c'\n", scanner->data[current]);
          exit(-3);

        }
    }
  }

  return tokens;
}
