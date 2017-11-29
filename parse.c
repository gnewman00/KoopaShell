#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "parse.h"

char ** parseCommand(char * command){
  int i = 0;
  char space[] = " ";
  int num_args = countArgs(command);
  // printf("%d\n", num_args);
  char ** args = calloc(num_args + 1, sizeof(char *));
  //  printf("%s\n", command);
  while(command){
    args[i] = strsep(&command, space);
    i++;
  }
 char * newline = strchr(args[num_args - 1], '\n');
 *newline = 0;
  args[num_args] = 0;
  return args;

}


int countArgs(char * i){
  if (*i == '\n'){ // if the inputted string is null
    return 0;
  }
  int num_args;
  for (num_args = 1; *i; i++){
    if (*i == ' '){
      num_args ++;
    }
  }
  return num_args;

}