#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tokenizer.h"
#include "history.h"

int main() {
  List *history = init_history();

  char input[100];

  while (1) {
    printf("Give me a string: I'll return tokens.\nInput ! followed by a number(i.e !1) to pull up the specific history if it exists.\nh for history and q to quit\n");
    printf("$ ");
    fgets(input, sizeof(input), stdin);

    if (input[0] == '!' && isdigit(input[1])) {
      int input_value = atoi(input + 1);
      printf("Entry:%d %s\n", input_value, get_history(history, input_value));
    }
    else if(strcmp(input, "h\n") == 0) {
      print_history(history);
    }
    else if (strcmp(input, "q\n") == 0) {
      free_history(history);
      goto done;
    }
    else{
      char **tokens = tokenize(input);
      print_tokens(tokens);
      free_tokens(tokens);
      add_history(history, input);
    }
  }
    
  done:
  return 0;
}
