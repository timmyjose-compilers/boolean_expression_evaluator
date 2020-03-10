#include "../headers/linked_list.h"
#include "../headers/evaluator.h"

#define MAX_STR_LEN 10000

int main(int argc, char *argv[])
{
  char s[MAX_STR_LEN];
  char t[MAX_STR_LEN];

  scanf("%[^\n]s", s);
  scanf(" %[^\n]s", t);

  Token *sample_token = init_token("Paren", "(");
  printf("sample token: %s, %s\n", sample_token->name, sample_token->spelling);
 
  return 0;
}
