#include "final.h"

int is_logged_in = 0;
char user[64];
char password[64];

int execute(char * line){
    char usr[64];
    char pwd[64];
  if (!strcmp(line, "help")){ ///Instructions on commands available
      printf("To sign up, type 'sign up'\n");
      printf("To sign in, type 'sign in'\n");
      printf("To sign out, type 'sign out'\n");
      printf("To create game, type 'create game'\n");
      printf("To join game, type 'join game'\n");
      printf("To exit the game, type 'exit'\n");
  } else if (!strcmp(line, "sign up")) {
      printf("Please enter in a username: ");
      fgets(usr, sizeof(usr), stdin);
      printf("Please enter in a password: ");
      fgets(pwd, sizeof(pwd), stdin);
      if(signup(usr,pwd)) {
          printf("Error: username taken. please try another.\n");
      } else {
          printf("Please proceed to sign in.\n");
      }

  } else if (!strcmp(line, "sign in")){
      printf("Please enter in your username: ");
      fgets(usr, sizeof(usr), stdin);
      printf("Please enter in your password: ");
      fgets(pwd, sizeof(pwd), stdin);
      if (signin(usr, pwd)) {
          printf("Error: cannot find user or password. Please retry.\n");
      } else {
          is_logged_in = 1;
          strcpy(user, usr);
          strcpy(password, pwd);
          printf("Signed in!\n");
      }
  } else if (!strcmp(line, "sign out")){
        if (signout(user)) {
          printf("Error: cannot find user. Please retry.\n");
        } else {
          is_logged_in = 0;
          user[0] = 0;
          password[0] = 0;
          printf("Signed out!\n");
        }
  } else if(!strcmp(line, "create game") && is_logged_in){ //Create gameplay
    gamePlay();
  } else if(!strcmp(line, "join game") && is_logged_in){
      printf("Joined game!\n");
  } else if(!strcmp(line, "exit")){
      if(is_logged_in) {
          execute("sign out");
      }
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
