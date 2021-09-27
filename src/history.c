#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List *history = (List*)malloc(sizeof(List));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str) {
  //create node with new entry and pointer to head
  Item *head = list->root;
  Item *newNode = (Item*)malloc(sizeof(Item));
  newNode->next = NULL;

  if (head == NULL) {
    list->root = newNode;
    newNode->id=0;  
  }
  else {
    while (head->next != NULL){
      head = head->next;
    }
    head->next = newNode;
    newNode->id = head->id + 1;
  }

  int length = 0;

  while (*str != '\0') {
    length++;
    str++;
  }

  str= str-length;
  char *histString = copy_str(str,length);
  newNode->str = histString;
}
char *get_history (List *list, int id) {
  Item *head = list->root;

  if (head == NULL) {
    return "History is empty";
  }
  
  while (head != NULL) {
    if (head->id == id){
      return head->str;
    }
    head = head->next;
  }
  return "error id not found";
}

void print_history (List *list){
  Item *head = list->root;

  while (head != NULL) {
    printf("Entry:%d %s\n", head->id, head->str);
    head = head->next;
  }
}
void free_history (List *list) {
  Item *head;

  while (list->root != NULL) {
    head = list->root;
    list->root = list->root->next;
    free(head->str);
    free(head);
  }
  free(list);
}
