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
int count_tokens(char *str)
{
  int count = 0;
  char *start, *end;
  end = str;
  while(start = token_start(end))
    {
      end = token_terminator(start);
      count++;
    }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char* newStr = (char*) malloc ((len+1) * sizeof(char));
  char* inPtr = inStr;
  char* newPtr = newStr;
  while (len > 0 && *inPtr != '\0')
    {
      *newPtr = *inPtr;
      newPtr++;
      inPtr++;
      len--;
    }
  *newPtr = '\0';
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
char **tokenize(char* str)
{
  int tokenCount = count_tokens(str);
  char **tokens = (char **)malloc((tokenCount +1) * sizeof(char *));
  char* start;
  char* end = str;
  for(int i = 0; i < tokenCount; i++)
    {
      start = token_start(end);
      end = token_terminator(start);
      tokens[i] = copy_str(start, end - start);
    }
  tokens[tokenCount] = NULL;
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  for(int i = 0; tokens[i] != NULL; i++)
    {
      printf("Token #%d: %s\n", i, tokens[i]);
    }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  char** ptr = tokens; 
  while ( *ptr != NULL) {
    free(*ptr);
  }
  free(tokens);
}
