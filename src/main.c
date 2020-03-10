#include "../headers/linked_list.h"
#include "../headers/scanner.h"
#include "../headers/evaluator.h"

#define MAX_STR_LEN 10000

int main(int argc, char *argv[])
{
  char s[MAX_STR_LEN];
  char t[MAX_STR_LEN];

  scanf("%[^\n]s", s);
  scanf(" %[^\n]s", t);

  LinkedList *list_int = ll_init();

  for (int i = 0; i < 10; i++) {
    ll_push_back_int(list_int, i);
  }

  ll_print_int(list_int);

  ll_destroy(list_int);

  LinkedList *list_string = ll_init();
  ll_push_back_string(list_string, "Hello");
  ll_push_back_string(list_string, "world");
  ll_push_back_string(list_string, "we");
  ll_push_front_string(list_string, "meet");
  ll_push_front_string(list_string, "again, isn't that nice?");

  ll_print_string(list_string);
  ll_destroy(list_string);

  LinkedList *list_token = ll_init();
  Token *lparen = init_token("lparen", "(");
  ll_push_back_token(list_token, lparen);

  Token *add = init_token("name", "add");
  ll_push_back_token(list_token, add);

  Token *rparen = init_token("rparen", ")");
  ll_push_back_token(list_token, rparen);

  ll_print_token(list_token);
  ll_destroy(list_token);

  return 0;
}
