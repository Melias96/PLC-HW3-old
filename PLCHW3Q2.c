#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
bool Delimiter(char ch){
  if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
      ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
      ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
      ch == '[' || ch == ']' || ch == '{' || ch == '}')
      return (true);
  return (false);
}
bool Operator(char ch){
  if (ch == '+' || ch == '-' || ch == '*' ||
      ch == '/' || ch == '>' || ch == '<' ||
      ch == '=')
      return (true);
  return (false);
}
bool vIdentifier(char* str){
  if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
      str[0] == '3' || str[0] == '4' || str[0] == '5' ||
      str[0] == '6' || str[0] == '7' || str[0] == '8' ||
      str[0] == '9' || Delimiter(str[0]) == true)
      return (false);
  return (true);
}
bool sSymbol(char ch){
  if (ch == '!' || ch == '@' || ch == '#' || ch == '$' ||
      ch == '%' || ch == '^' || ch == '&' || ch == '*' ||
      ch == '(' || ch == ')')
      return (true);
  return (false);
}
bool Keyword(char* str){
    if (!strcmp(str, "goku") || !strcmp(str, "vegeta") ||
        !strcmp(str, "gohan") || !strcmp(str, "trunks") ||
        !strcmp(str, "bulma") ||
         !strcmp(str, "chichi") || !strcmp(str, "goten")
        || !strcmp(str, "piccalo") || !strcmp(str, "krillen")
        || !strcmp(str, "kami") || !strcmp(str, "popo"))
        return (true);
    return (false);
}
bool Integer(char* str){
  int i, len = strlen(str);
  if (len == 0)
      return (false);
  for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2'
          && str[i] != '3' && str[i] != '4' && str[i] != '5'
          && str[i] != '6' && str[i] != '7' && str[i] != '8'
          && str[i] != '9' || (str[i] == '-' && i > 0))
          return (false);
  }
  return (true);
}
bool rNumber(char* str){
  int i, len = strlen(str);
  bool hasDecimal = false;
  if (len == 0)
      return (false);
  for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2'
          && str[i] != '3' && str[i] != '4' && str[i] != '5'
          && str[i] != '6' && str[i] != '7' && str[i] != '8'
          && str[i] != '9' && str[i] != '.' ||
          (str[i] == '-' && i > 0))
          return (false);
      if (str[i] == '.')
          hasDecimal = true;
  }
  return (hasDecimal);
}
char* sString(char* str, int left, int right){
    int i;
    char* subStr = (char*)malloc(
                  sizeof(char) * (right - left + 2));
 
    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}
void parse(char* str){
  int left = 0, right = 0;
  int len = strlen(str);
  while (right <= len && left <= right) {
      if (Delimiter(str[right]) == false)
          right++;
      if (Delimiter(str[right]) == true && left == right) {
          if (Operator(str[right]) == true)
              printf("'%c' IS AN OPERATOR\n", str[right]);

          right++;
          left = right;
      } 
      else if (Delimiter(str[right]) == true && left != right || (right == len && left != right)) {
        char* subStr = sString(str, left, right - 1);
        if (Keyword(subStr) == true)
        printf("'%s' IS A KEYWORD\n", subStr);
        else if (Integer(subStr) == true)
        printf("'%s' IS AN INTEGER\n", subStr);
        else if (rNumber(subStr) == true)
        printf("'%s' IS A REAL NUMBER\n", subStr);
        else if (vIdentifier(subStr) == true && Delimiter(str[right - 1]) == false)
        printf("'%s' IS A VALID IDENTIFIER\n", subStr);
        else if (vIdentifier(subStr) == false && Delimiter(str[right - 1]) == false)
        printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
        left = right;
    }
  }
  return;
}

int maximum(int x, int y) {
  if (x > y)  
  return x;
  else {
    return y;
  }
} 
int main(){
  char str[100] = "int a = b + 1c; ";
  parse(str); 
  return (0);
}
