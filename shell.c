#include "final.h"

int is_logged_in = 0;
char user[1024];
char password[1024];

int execute(char * line){
  if (!strcmp(line, "help")){ ///Instructions on commands available
      printf("To sign up, type 'sign up'\n");
      printf("To sign in, type 'sign in'\n");
      printf("To sign out, type 'sign out'\n");
      printf("To create game, type 'create game'\n");
      printf("To join game, type 'join game'\n");
      printf("To exit the game, type 'exit'\n");
      char usr[1024];
      char pwd[1024];
  } else if (!strcmp(line, "sign up")) {
      printf("Please enter in a username: ");
      fgets(usr, sizeof input, stdin);
      printf("Please enter in a password: ");
      fgets(pwd, sizeof input, stdin);
      if(signup(usr,pwd)) {
          printf("Error: username taken. please try another.");
      } else {
          printf("Please proceed to sign in.");
      }

  } else if (!strcmp(line, "sign in")){
      printf("Please enter in your username: ");
      fgets(usr, sizeof input, stdin);
      printf("Please enter in your password: ");
      fgets(pwd, sizeof input, stdin);
      if (signin(usr, pwd)) {
          printf("Error: cannot find user or password. Please retry.");
      } else {
          is_logged_in = 1;
          user = usr;
          password = pwd;
          printf("Signed in!\n");
      }
  } else if (!strcmp(line, "sign out")){
        if (signout(user, password)) {
          printf("Error: cannot find user or password. Please retry.");
        } else {
          is_logged_in = 0;
          user = NULL;
          password = NULL;
          printf("Signed out!\n");
        }
  } else if(!strcmp(line, "create game") && is_logged_in){ //Create gameplay
    gamePlay();
  } else if(!strcmp(line, "join game") && is_logged_in){
      printf("Joined game!\n");
  } else if(!strcmp(line, "exit")){
      if(logged)
      return 1; //exits the entire program
  } else {
      printf("Command not valid!\n");
  }
  return 0;
}

int createshell(){
    char input[1024];
    printf("welcome to Battleship!\n");
    printf("If you're new to this game, type in 'help' to see the list of valid commands!\n");
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
