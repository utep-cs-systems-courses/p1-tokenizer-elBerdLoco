#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"
/*
argv[0] contains the programs name, argv[1] contaains the string input
 */
#define MAX_INPUT 256

int main(){
  char input[MAX_INPUT];
  while (1){
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = '\0';
    
    printf("%s\n");
    if(strncmp(input, "exit", MAX_INPUT) == 0) {break;}

    for (int i = 0; i < strlen(input); i++){
      if(space_char(input[i])) {printf("Space found\n");}
      if(non_space_char(input[i])){printf("Character found\n");}
    }
    char *start = token_start(input);
    while (start != NULL) {
      printf("Token: %s\n", start);
      start++;
      
      start = token_start(start+strlen(start));
      printf("Token: %s\n", start);
      
    }
  }
  return 0;
}
