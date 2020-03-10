#include "../headers/linked_list.h"

Node *create_node(char *data)
{
  Node *node = malloc(sizeof(Node));

  if (node == NULL) {
    fprintf(stderr, "Could not create linked list node. Allocator returned NULL.\n");
    exit(-1);
  }

  node->data = malloc(sizeof(char) * strlen(data));
  strncpy(node->data, data, strlen(data));
  node->prev = node->next = NULL;

  return node;
}

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
    if (list->head) free(list->head);
    if (list->tail) free(list->tail);
    free(list);
  }
}

void ll_push_front(LinkedList *list, char *data)
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

void ll_push_back(LinkedList *list, char *data)
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

char *ll_pop_front(LinkedList *list)
{
  if (ll_is_empty(list)) {
    fprintf(stderr, "trying to pop_front an empty list.\n");
    exit(-2);
  }

  char *data = malloc(sizeof(char) * strlen(list->head->data));
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

char *ll_pop_back(LinkedList *list)
{
  if (ll_is_empty(list)) {
    fprintf(stderr, "trying to pop_back an empty list.\n");
    exit(-2);
  }

  char *data = malloc(sizeof(char) * strlen(list->tail->data));
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

bool ll_is_empty(const LinkedList *list)
{
  return list->head == NULL;
}

void ll_print(const LinkedList *list)
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
