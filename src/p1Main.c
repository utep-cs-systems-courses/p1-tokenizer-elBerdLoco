#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

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
    
  }
  
  //printf("The program name is <%s>\n", *argv);
  //char *exa = "I am the example";
  
  
  
  //printf("Example String %s\n", strExa);
  /*
    If *p = "Hello there", then **p = "Hello", and **p+1 = "there" 
   */
  //char **p= &argv[1];
  // char **y= &argv[1];
  //size_t length = strlen(argv[1]);
  //char *k = argv[1];
  //char i = tokenstart(*p);
  
  /*for (;  *p != NULL ; p++){
    printf("Argument: %s\n", *p);
    
    }*/
  
  /* printf("Pointer argument: %s\n", k);
  printf("Exited from Argument\n");
  printf("Pointer exa manipulation: %s\n", exa+0);
  printf("Testing space_char: %d\n",  space_char(*exa+1));
  p--;
  printf("Pointer p subtracted by 1: %s\n", *p);
  /* char *str = argv[1];
  printf("uncut token: %s\n", str);
  
  char **tokens;
  tokens = tokenize(str);

  print_tokens(tokens);
  
  free_tokens(tokens);
  
  char **tokens = tokenize(k);
  printf("debug");
  print_tokens(tokens);
  */
  return 0;
}
