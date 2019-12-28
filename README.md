# final-mks65
System Level Programming Final Project </br>
Team members: Kaitlyn Lau, Emily Zhang </br>
Project: Create a simple program where users can log in to play and join battleship games that can be played on a terminal.

### User Interface (UI):  
* A quick start guide to teach users how to use the program will be provided after creating an account, and a keyword “help” will be used if users desire a review in controls
* Empty input would trigger a prompt to remind users that they can use the help keyword to find the available keywords for use
* Users will be able to navigate with the shell to create a room, join a game, and to play
* Gameplay will similarly be controlled by the shell: users will be able to navigate the game board through coordinates and keywords
#### Note: interesting further implementation could include setting a default game setup for users and creating an interface so that users can easily place their ships using arrow keys.

### Technical Design:
Topics used:
* Shared memory and semaphores to save data of user login information
* Allocating memory to save in-game data
* Leaderboards and personal game records will be recorded in files and would be updated after each game and can be reported to user through reading
* Pipes will be used for 2 users playing a game (further implementation could be allowing other users to watch a game in progress)
* Signals to block people accidentally using ctrl-C to quit the program. The “exit” keyword will end the program.
* Networking???

### Task Delegation:
* Basic shell implementation - Kaitlyn
  * creating/joining games
  * help
* User interface implementation - Emily
  * sign up
  * log in
  * authentication
  * using shared memory
* Gameplay:
  * gaming shell & board - Emily
* Leaderboard - Kaitlyn
  * Use file to keep score and display

### Data Structures:
  * Arrays
    * Hold character arrays for the usernames, passwords, and other pieces of user information
    * May be used to construct the game board
  * Structs
    * Label and identify the parts of the board such as a "miss", "hit", and the location of the ships

### Algorithms:
	*

### Timeline:
