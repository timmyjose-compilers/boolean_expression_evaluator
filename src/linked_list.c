#include "../headers/linked_list.h"

/* Private API */
Node *create_node(void *data)
{
  Node *node = malloc(sizeof(Node));

  if (node == NULL) {
    fprintf(stderr, "Could not create linked list node. Allocator returned NULL.\n");
    exit(-1);
  }

  node->data = malloc(sizeof(void*) * strlen(data));
  strncpy(node->data, data, strlen(data));
  node->prev = node->next = NULL;

  return node;
}

void ll_push_front(LinkedList *list, void *data)
{
  Node *node = create_node(data);

  if (list->head == NULL) {
    list->head = list->tail = node;  
  } else {
    list->head->prev = node;
    node->next = list->head;
    list->head = node;
  }
}

void ll_push_back(LinkedList *list, void *data)
{
  Node *node = create_node(data);

  if (list->head == NULL) {
    list->head = list->tail = node;
  } else {
    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
  }
}

void *ll_pop_front(LinkedList *list)
{
  if (ll_is_empty(list)) {
    fprintf(stderr, "trying to pop_front an empty list.\n");
    exit(-2);
  }

  void *data = malloc(sizeof(void) * strlen(list->head->data));
  strncpy(data, list->head->data, strlen(list->head->data));

  Node *head = list->head;
  list->head = list->head->next;
  free(head);

  if (list->head != NULL)
    list->head->prev = NULL;
  else
    list->tail = NULL;

  return data;
}

void *ll_pop_back(LinkedList *list)
{
  if (ll_is_empty(list)) {
    fprintf(stderr, "trying to pop_back an empty list.\n");
    exit(-2);
  }

  void *data = malloc(sizeof(void) * strlen(list->tail->data));
  strncpy(data, list->tail->data, strlen(list->tail->data));

  Node *tail = list->tail;
  list->tail = list->tail->prev;
  free(tail);

  if (list->tail != NULL)
    list->tail->next = NULL;
  else
    list->head = NULL;

  return data;
}

/* Public API */

LinkedList *ll_init()
{
  LinkedList *list = malloc(sizeof(LinkedList));

  if (list == NULL) {
    fprintf(stderr, "Could not create linked list. Allocator returned NULL.\n");
    exit(-1);
  }

  list->head = list->tail = NULL;

  return list;
}

void ll_destroy(LinkedList *list)
{
  if (list) {
    /* FIXME: traverse list, freeing nodes */
    if (list->head) free(list->head);
    if (list->tail) free(list->tail);
    free(list);
  }
}

bool ll_is_empty(const LinkedList *list)
{
  return list->head == NULL;
}

void ll_print_int(const LinkedList *list)
{
  if (ll_is_empty(list)) {
    fprintf(stderr, "list is empty.\n");
    return;
  } 

  Node *temp = list->head;
  while (temp != NULL) {
    printf("%d", *(int*)temp->data);
    if (temp != list->tail)
      printf(" -> ");
    temp = temp->next;
  }
  puts("");
}

void ll_print_string(const LinkedList *list)
{
  if (ll_is_empty(list)) {
    fprintf(stderr, "list is empty.\n");
    return;
  } 

  Node *temp = list->head;
  while (temp != NULL) {
    printf("%s", temp->data);
    if (temp != list->tail)
      printf(" -> ");
    temp = temp->next;
  }
  puts("");
}

void ll_print_token(const LinkedList *list)
{
  if (ll_is_empty(list)) {
    fprintf(stderr, "list is empty.\n");
    return;
  } 

  Node *temp = list->head;
  while (temp != NULL) {
    Token *data = (Token*)temp->data;

    printf("{ name: %s, spelling: %s }", data->name, data->spelling);
    if (temp != list->tail)
      printf(" -> ");
    temp = temp->next;
  }
  puts("");
}

void ll_push_back_int(LinkedList *list, int value)
{
  int *list_value = malloc(sizeof(int));

  if (list_value == NULL) {
    fprintf(stderr, "Could not allocate memory for int value - allocator returned NULL.\n");
    exit(-1);
  }

  *list_value = value;
  ll_push_back(list, (void*)list_value);
}

void ll_push_front_int(LinkedList *list, int value)
{
  int *list_value = malloc(sizeof(int));

  if (list_value == NULL) {
    fprintf(stderr, "Could not allocate memory for int value - allocator returned NULL.\n");
    exit(-1);
  }

  *list_value = value;
  ll_push_front(list, (void*)&value);
}

int ll_pop_front_int(LinkedList *list)
{
  return *(int*)ll_pop_front(list);
}

int ll_pop_back_int(LinkedList *list)
{
  return *(int*)ll_pop_back(list);
}

void ll_push_back_string(LinkedList *list, const char *s)
{
  ll_push_back(list, (void*)s);
}

void ll_push_front_string(LinkedList *list, const char *s)
{
  ll_push_back(list, (void*)s);
}

const char *ll_pop_front_string(LinkedList *list)
{
  return (const char*)ll_pop_front(list);
}

const char *ll_pop_back_string(LinkedList *list)
{
  return (const char*)ll_pop_back(list);
}

void ll_push_back_token(LinkedList *list, Token *t)
{
  ll_push_back(list, (void*)t);
}

void ll_push_front_token(LinkedList *list, Token *t)
{
  ll_push_front(list, (void*)t);
}

Token *ll_pop_front_token(LinkedList *list)
{
  return (Token*)ll_pop_front(list);
}

Token *ll_pop_back_token(LinkedList *list)
{
  return (Token*)ll_pop_back(list);
}
