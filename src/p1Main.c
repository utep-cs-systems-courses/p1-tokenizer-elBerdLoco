#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/*
argv[0] contains the programs name, argv[1] contaains the string input
 */
int main(int argc, char **argv){
  printf("The program name is <%s>\n", *argv);
  
  /*
    If *p = "Hello there", then **p = "Hello", and **p+1 = "there" 
   */
  for (char** p = &argv[1]; *p; p++){
    printf("Argument: %s\n", *p);
  }
  printf("Exited from Argument");
  char*x = argv[1];
  int tokenNum = count_tokens(x); 
    
  /* char *str = argv[1];
  printf("uncut token: %s\n", str);
  
  char **tokens;
  tokens = tokenize(str);

  print_tokens(tokens);
  
  free_tokens(tokens);
  */

  return 0;
}
