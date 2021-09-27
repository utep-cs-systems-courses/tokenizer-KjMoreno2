#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

//checks if a character is tab or space
int space_char(char c){
  if (c == '\t' || c == ' ')
    return 1;
  else
    return 0;
}

//checks if a character is not a space or tab
int non_space_char(char c){
  if(c == '\t' || c == ' ' || c == '\0')
    return 0;
  else
    return 1;
}

//returns pointer at the start of word
char *word_start(char *str){
  while(space_char(*str))
    str++;
  return str;
}

char *word_terminator(char *word){
  while(non_space_char(*word)){
    word++;
  }
    return word;
}

int count_words(char *str){
  int count = 0;
  while(*str != '\0'){
    str = word_start(str);
    str = word_terminator(str);
    count++;
  }
  return count;
}

char *copy_str(char *inStr, short len){
  char *copy = (char*)malloc((len+1)*sizeof(char));
  for(int i = 0; i < len; i++){
    *(copy+i) = *(inStr+i);
  }
  *(copy+(len)) = '\0';
  return copy;
}

char **tokenize(char *str){
  int count = count_words(str);
  char **ptr_array = (char**)malloc((count+1)*sizeof(char*));
  char *stop;
  char *start = word_start(str);

  for (int i = 0; i < count; i++) {
    stop = word_terminator(start);
    *(ptr_array+i) = copy_str(start, (stop-start));
    start = word_start(stop);
  }
  *(ptr_array+count) = NULL;
  return ptr_array;
}

void print_tokens(char **tokens){
  for (int i =0; tokens[i] != '\0'; i++) {
    printf("%s\n", tokens[i]);
  }
}

void free_tokens(char **tokens){
  for (int i = 0; tokens[i] != '\0'; i++) {
    free(tokens[i]);
  }
}   
