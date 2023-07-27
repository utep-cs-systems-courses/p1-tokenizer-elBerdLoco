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

  //space and non space char
  char* a = "Ben is cool";
  char* b = " ";
  int ans1, ans2;
  
  printf("Test Space & non space\na = %s\nb = %s\n", a, b);
  ans1 = space_char(*a);
  ans2 = space_char(*b);
  printf("a: %d\nb: %d\n",ans1, ans2);

  //token start and token terminator
  char* start = "     Hello World";
  char* ans3;
  char* ans4;
  
  printf("Test for token start and token terminator\nUsing string: %s\n", start);
  ans3 = token_start(start);
  printf("Start: %s\n", ans3);
  ans4 = token_terminator(ans3);
  printf("Terminator: %s\n", ans4);

  //count tokens
  char* countTokens = "My dog has fleas";
  int ans5;
  printf("Test for token count\nUsing string: %s\n", countTokens);
  ans5 = count_tokens(countTokens);
  printf("Total: %d\n", ans5);

  //copy string
  char* string = "Hello, world!";
  short len = 5;
  printf("Test for copy token\nUsing string: %s\n", string);
  char* newString = copy_str(string, len); 
  printf("New string: %s\n", newString);

  //tokenize, print tokens, & free tokens
  char* tokenString = "My dog is derpy";
  printf("String being tokenized: %s\n", tokenString);
  char** tokens = tokenize(tokenString);
  for(int i = 0; tokens[i] != NULL; i++)
    {
      printf("Token #%d: %s\n", i, tokens[i]);
    }
  printf("Testing print tokens\n");
  print_tokens(tokens);
  //Free tokens should cause a crash when trying to access the freed tokens
  printf("Testing if memory is being freed\n");
  free_tokens(tokens);
  if(tokens == NULL)
    {
     printf("It didn't work\n");
    }
  return 0;
}
