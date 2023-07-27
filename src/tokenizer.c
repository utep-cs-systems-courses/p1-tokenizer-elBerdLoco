#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tokenizer.h"


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
/* int space_char(char c){
  return ((c == ' ' || c == '\t') && c !='\0');
}
*/

int space_char(char c){
  return ((c == ' ' || c == '\t') && c != '\0');
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  return !space_char(c);
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str)
{
  while (*str != '\0')
    {
      if(non_space_char(*str))
	{
	  return str;
	}
      str++;
    }
  //put return NULL here when rewriting the function.
  return NULL;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
  char *ter = token;
  while (*ter != '\0')
    {
    if(space_char(*ter)){
      return ter;
    }
    ter++;
  } 
  return ter;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
  int count = 0;
  char *token1, *token2;
  token1 = str;
  while(*token1 != '\0' ){
    token2 = token_terminator(token1);
    count++;
    token1 = token_start(token2);
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *newStr = (char *)malloc((len + 1) * sizeof(char));
  for(int i = 0; i<len; ++i){
    newStr[i] = inStr[i];
  }
  newStr[len] = '\0';
  return newStr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  int tokenCount = count_tokens(str);
  char **tokens = (char **)malloc((tokenCount +1) * sizeof(char *));
  char *token = token_start(str);
  int i = 0;
  while (token != NULL) {
    char *terminator = token_terminator(token);
    int tokenLength = terminator - token;
    tokens[i] = copy_str(token, tokenLength);
    token = token_start(terminator + 1);
    i++;
  }
  tokens[tokenCount] = NULL;
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  int i = 0;
  while (tokens[i] != NULL) {
    printf("%s\n", tokens[i]);
    i++;
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  int i = 0;
  while (tokens[i] != NULL) {
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
