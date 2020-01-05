#include "final.h"

int execute(char * line){
  if (!strcmp(line, "help")){
    printf("To sign in, type 'sign in'\n");
    printf("To log in, type 'log in'\n");
    printf("To create game, type 'create game'\n");
    printf("To join game, type 'join game'\n");
    printf("To exit the game, type 'exit'\n");
  } else if (!strcmp(line, "sign in")){
    printf("Signed in!\n");
  } else if (!strcmp(line, "log in")){
    printf("Logged in!\n");
  } else if(!strcmp(line, "create game")){
    printf("Created game!\n");
  } else if(!strcmp(line, "join game")){
    printf("Joined game!\n");
  } else if(!strcmp(line, "exit")){
    return 1; //exits the entire program
  } else {
    printf("Command not valid!\n");
  }
}

int createshell(){
    char input[1024];
    while(1) {
        printf("Enter in a command: ");
        fgets(input, sizeof input, stdin);
        input[strlen(input) - 1] = '\0';
        if(execute(input)){
            break;
        }
    }
    return 0;
}
