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
  printf("Total: %d", ans5);
  
  return 0;
}
