#include "final.h"

void initializeBoard(struct cell gameBoard[ROWS][COLS]){
  for (int i = 0; i < ROWS; i++){
    for (int j = 0; j < COLS; j++) {
      gameBoard[i][j].symbol = WATER;
      gameBoard[i][j].position.row = i;
      gameBoard[i][j].position.col = j;
    }
  }
}

void printBoard(struct cell gameBoard[ROWS][COLS]){
  printf("  0 1 2 3 4 5 6 7 8 9\n");
  for (int i = 0; i < ROWS; i++) {
    char temp = i + 65;
    printf("%c ", temp);
    for (int j = 0; j < COLS; j++) {
      switch(gameBoard[i][j].symbol){
        case HIT: printf("%c ", HIT); break;
        case MISS: printf("%c ", MISS); break;
        case CARRIER: printf("%c ", CARRIER); break;
        case BATTLESHIP: printf("%c ", BATTLESHIP); break;
        case CRUISER: printf("%c ", CRUISER); break;
        case SUBMARINE: printf("%c ", SUBMARINE); break;
        case DESTROYER: printf("%c ", DESTROYER); break;
        case WATER:
        default: printf("%c ", WATER); break;
      }
    }
    printf("\n");
  }
}

int putShip (struct cell gameBoard[ROWS][COLS], struct ship input, struct coordinate position, int direction){
  for (int i = 0; i < input.length; i++) {
    if (direction){ //Vertical
      gameBoard[position.row + i][position.col].symbol = input.symbol;
    }
    else { //Horizontal
      gameBoard[position.row][position.col + i].symbol = input.symbol;
    }
  }
  return 1;
}

int isCoorValid(struct cell gameBoard[ROWS][COLS], struct ship input, struct coordinate position, int direction){
  if(direction) {//Vertical
    if((position.row + (input.length-1)) > 9) {//out of bounds
      return 0;
    }
  }
  else {
    if((position.col + (input.length-1)) > 9) {//out of bounds
      return 0;
    }
  }
  for (int i = 0; i < input.length; i++) {
    if (direction){ //Vertical
      if(gameBoard[position.row + i][position.col].symbol != WATER){
        return 0; //intersects another ship, return 0
      }
    }
    else { //Horizontal
      if(gameBoard[position.row][position.col + i].symbol != WATER) {
        return 0; //intersects another ship, return 0
      }
    }
  }
  return 1; //coordinate valid!
}

int isWin (struct cell gameBoard[ROWS][COLS]){ //returns true if no one won yet, 0 if someone won
  for (int i = 0; i < ROWS; i++){
    for (int j = 0; j < COLS; j++) {
      if(gameBoard[i][j].symbol == CARRIER || gameBoard[i][j].symbol == BATTLESHIP || gameBoard[i][j].symbol == CRUISER || gameBoard[i][j].symbol == SUBMARINE || gameBoard[i][j].symbol == DESTROYER){
        return 1;
      }
    }
  }
  return 0;
}
void addShiptoBoard(struct cell gameBoard[ROWS][COLS], struct ship input, char shipType, int shipLength){
  while (1){
    printf("Coordinate: ");
    char coor[10];
    char direc[10];
    fgets(coor, sizeof(coor), stdin);
    printf("Direction: ");
    fgets(direc, sizeof(direc), stdin);
    struct coordinate coor1;
    input.symbol = shipType;
    input.length = shipLength;
    coor1.row = coor[0] - 65;
    coor1.col = coor[1] - 48;
    if(isCoorValid(gameBoard, input, coor1, (int)direc[0]-48)){
      putShip(gameBoard, input, coor1, (int)direc[0] - 48);
      break;
    }
    printf("Coordinate Not Valid! Try Again.\n");
  }
  printBoard(gameBoard);
  printf("\n");
}

int hitTarget(struct cell gameBoard[ROWS][COLS], struct coordinate position){
  while(1){
    if(position.row >= 0 && position.row <= 9 && position.col >= 0 && position.col <= 9){ //checks to see if coordinate entered is within range
      if(gameBoard[position.row][position.col].symbol == WATER){
        gameBoard[position.row][position.col].symbol = MISS;
        printf("Your Board:\n");
        printBoard(gameBoard);
        printf("MISS\n");
        return 1; // MISS
        break;
      }
      else if(gameBoard[position.row][position.col].symbol == CARRIER || gameBoard[position.row][position.col].symbol == BATTLESHIP || gameBoard[position.row][position.col].symbol == CRUISER || gameBoard[position.row][position.col].symbol == SUBMARINE || gameBoard[position.row][position.col].symbol == DESTROYER){
        gameBoard[position.row][position.col].symbol = HIT;
        printf("Your Board:\n");
        printBoard(gameBoard);
        printf("HIT\n");
        return 2; //HIT
        break;
      }
      else if(gameBoard[position.row][position.col].symbol == HIT || gameBoard[position.row][position.col].symbol == MISS){
        printf("This Coordinate Was Already Targeted!\n");
        break;
      }
    }
    else { //if coordinate not valid, ask for another one
      printf("Coordinate Not Valid! Try Again.\n");
    }
  }
  return 0;
}

void gamePlay(struct cell ownBoard[ROWS][COLS], struct cell mainBoard[ROWS][COLS]){
  initializeBoard(ownBoard);
  initializeBoard(mainBoard);
  printBoard(ownBoard);
  printf("\n");
  printf("Now, place your ships! Enter in a coordinate pair of where you want your ship to start.\n");
  printf("\n");
  printf("If you're going horizontally, enter in the leftmost coordinate of where you want your ship to be.\n");
  printf("If you're going vertically, enter in the highest coordinate of where you want your ship to be.\n");
  printf("\n");

  //place all the ships down
  struct ship carrier;
  struct ship battleship;
  struct ship cruiser;
  struct ship submarine;
  struct ship destroyer;
  printf("Place your carrier! Ship length: 5. Enter in the coordinate in this format: A2\n");
  printf("Enter in the direction in this format: 0 for Horizontal and 1 for Vertical\n");
  addShiptoBoard(ownBoard, carrier, CARRIER, CL);
  printf("Place your battleship! Ship length: 4. Enter in the coordinate in this format: A2\n");
  printf("Enter in the direction in this format: 0 for Horizontal and 1 for Vertical\n");
  addShiptoBoard(ownBoard, battleship, BATTLESHIP, BL);
  printf("Place your cruiser! Ship length: 3. Enter in the coordinate in this format: A2\n");
  printf("Enter in the direction in this format: 0 for Horizontal and 1 for Vertical\n");
  addShiptoBoard(ownBoard, cruiser, CRUISER, CR);
  printf("Place your submarine! Ship length: 3. Enter in the coordinate in this format: A2\n");
  printf("Enter in the direction in this format: 0 for Horizontal and 1 for Vertical\n");
  addShiptoBoard(ownBoard, submarine, SUBMARINE, SL);
  printf("Place your destroyer! Ship length: 2. Enter in the coordinate in this format: A2\n");
  printf("Enter in the direction in this format: 0 for Horizontal and 1 for Vertical\n");
  addShiptoBoard(ownBoard, destroyer, DESTROYER, DL);

  //introduce the actual gameBoard, start the game
  printf("Your Game Board:\n");
  printBoard(ownBoard);
  printf("Main Game Board:\n");
  printBoard(mainBoard);

}

void playerOne(){
  printf("Now, make your first move! Enter in a coordinate you want to hit in this format: A2\n");
  printf("Only make a move when the screen shows 'Next Move Coordinate:'\n");
  int fd;
  char *playerMove = "pipes/pipe";
  mkfifo(playerMove, 0666);
  char hit1[10], hit2[10];
  while(isWin(playerOneBoard)){
    fd = open(playerMove, O_WRONLY);
    printf("Next Move Coordinate: ");
    fgets(hit1, 10, stdin);
    write(fd, hit1, strlen(hit1));
    close(fd);

    fd = open(playerMove, O_RDONLY);
    while(1){
      if(read(fd, hit2, sizeof(hit2)) >0 ){
          *strchr(hit2, '\n') = '\0';
          break;
      }
    }
    close(fd);
  struct coordinate coor; //marks whether hit or miss on player one's board
  coor.row = hit2[0] - 65;
  coor.col = hit2[1] - 48;
  int move = hitTarget(playerOneBoard, coor);

  //now, mark on player two's main board whether he got a hit or miss
  fd = open(playerMove, O_WRONLY);
  if(move == 1){
    strcat(hit2, "1"); //MISS
  }
  if(move == 2){
    strcat(hit2, "2"); //HIT
  }
  write(fd, hit2, strlen(hit2));
  close(fd);

  //now, read whether the previous move ended up being a hit or miss to playerTwo's main board
  fd = open(playerMove, O_RDONLY);
  while(1){
    if(read(fd, hit2, sizeof(hit2)) >0 ){
        *strchr(hit2, '\n') = '\0';
        break;
    }
  }
  close(fd);
  printf("Your Main Board:\n"); //show playerOne his own board
  printBoard(playerOneMain);
}
  printf("Player Two Won!\n");
}
void playerTwo(){
  printf("Now, make your first move! Enter in a coordinate you want to hit in this format: A2\n");
  printf("Only make a move when the screen shows 'Next Move Coordinate:'\n");
  int fd2;
  char *playerMove = "pipes/pipe";
  mkfifo(playerMove, 0666);
  char hit1[10], hit2[10];
  while(isWin(playerTwoBoard)){
    fd2 = open(playerMove, O_RDONLY);
    while(1){
      if(read(fd2, hit1, sizeof(hit1)) >0){
          *strchr(hit1, '\n') = '\0';
          break;
      }
    }
    close(fd2);
    struct coordinate coor; //marks whether hit or miss on player two's board
    coor.row = hit1[0] - 65;
    coor.col = hit1[1] - 48;
    int move = hitTarget(playerTwoBoard, coor);
    //now, mark on player one's main board whether he got a hit or miss
    fd2 = open(playerMove, O_WRONLY);
    if(move == 1){
      strcat(hit1, "1"); //MISS
    }
    if(move == 2){
      strcat(hit1, "2"); //HIT
    }
    write(fd2, hit1, strlen(hit1));
    close(fd2);

    //now, read whether the previous move ended up being a hit or miss to playerTwo's main board
    fd2 = open(playerMove, O_RDONLY);
    while(1){
      if(read(fd2, hit1, sizeof(hit1)) >0){
          *strchr(hit1, '\n') = '\0';
          break;
      }
    }
    close(fd2);

    printf("Your Main Board:\n");
    printBoard(playerTwoMain);
    fd2 = open(playerMove, O_WRONLY);
    printf("Next Move Coordinate: ");
    fgets(hit2, 10, stdin);
    write(fd2, hit2, strlen(hit2));
    close(fd2);
  }
  printf("Player One Won!\n");
}
