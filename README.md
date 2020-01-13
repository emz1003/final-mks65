# final-mks65
System Level Programming Final Project </br>
Team members: Kaitlyn Lau, Emily Zhang </br>
Project: Create a simple program where users can log in to play and join battleship games that can be played on a terminal.

### Devlog
1/2/20
* Kaitlyn: Coded the beginning of the user interface (shell.c)

1/5/20
* Kaitlyn: Made changes to the interface and editted the makefile to make it include shell.c
* Kaitlyn: Created the file gameplay.c, added it to the makefile
* Kaitlyn: Coded the functions initializeBoard (initializes a gameBoard) and printBoard (prints the board out), kept on editting until both functions worked

1/7/20
* Kaitlyn: Coded the function putShip (places a ship down on to the board)

1/8/20
* Kaitlyn: Coded the function gamePlay (contains the entire game play), debugged the function but the ships wouldn't be oriented in the right direction

1/9/20
* Kaitlyn: Worked for a long time to figure out the coordinate system of the board and place the ships down accordingly.
* Kaitlyn: putShip finally worked correctly

1/10/20
* Kaitlyn: Created the function addShiptoBoard to make putting the ships on the board more modular
* Kaitlyn: Somehow the coordinates were still messed up, I finally fixed everything

1/11/20
* Kaitlyn: To make sure that the coordinates the user inputs to place the ships are valid, I created the function isCoorValid. Tested it with the rest of the functions in gameplay.c and it works!
* Kaitlyn: Created the main gameBoard, formatted the game to print both your board and the main board together. But for some reason, the main board isn't setting up right...

1/12/20
* Kaitlyn: Main board is created correctly
* Kaitlyn: Coded the function hitTarget, which makes a target either a hit or a miss
* Kaitlyn: Also made hitTarget check if the coordinate entered was valid
* Kaitlyn: Tested everything, but it doesn't work. Must work on it tomorrow.

1/13/20
* Kaitlyn: After lots of debugging, the hitTarget works! Works great with the mainboard. Next steps: look at pipes for a two player game!

### Features:

### Attempted:


### Bugs:

### Files and Function Headers:
