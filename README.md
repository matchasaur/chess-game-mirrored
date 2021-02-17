![CHESS! Logo2](https://user-images.githubusercontent.com/77028662/108160872-c65c1800-709e-11eb-93f6-fb7f7576280d.png)


# Chess  :chess_pawn:

  Authors: (names listed in alphabetical order)<br />
[Chun Ho Wong](https://github.com/cwong165) :space_invader:  <br />
[Danial Mirza](https://github.com/danialmirza99) :wolf: <br />
[Francisco Quiroz](https://github.com/FrankyQuiroz01) :japanese_goblin: <br />
[Jared Tanuwidjaja](https://github.com/matchasaur) 🏄 <br />
 
<br />

## Phase I
**Project Description (Phase 1):**:video_game:

--The Project itself is interesting because it will not be a straightforward chess game, in the sense that we are required to have boards that are saved in case we ever want to hold off the game to a later date in which we would continue the game. 

--Not only that, we would also love to include A.I. in which we will have the computer be our opponent. This means we at the minimum must have an A.I. smart enough to recognize that
 - (1) A move is possible 🚶
 - (2) The importance of the king to prolong the game so that it does not end quickly 👑

*This is slightly more challenging and may be subject to change.*


<br />

**Languages/Tools/technologies**🧰
   * C++


**Input/output**:robot: 
  * Keyboard⌨
  * Mouse(*optional*)🖱
  * Monitor💻
  * Speaker(*optional*)🔊

**Design Patterns**🔋


[**Strategy (Behavioral Pattern)**](https://refactoring.guru/design-patterns/strategy) :speech_balloon:

- Why you picked this pattern and what feature you will implement with it?
   
  -  **We chose this pattern because it will allow us to implement a movement for each unique piece while maintaining organization and avoiding redundant code.**
    

-   What problem you anticipate encountering when implementing your project that you will solve using the design pattern?
    

    -  **Chess has six unique pieces, each with different movement patterns. Since we are not chess masters, It would not be easy to implement all the possible patterns and rules for chess in one go.**
    

-   Why the chosen design pattern will lead to a good solution to that problem?
    

    -   **Utilizing the Strategy pattern would allow us to construct a base ChessPiece class and divide each movement algorithm into separate strategies. This will allow us to reuse code if a chess piece shares a movement pattern identical to a different chess piece and preferably create AI player base on the same set of algorithms.**

[**Composite Pattern (structural design pattern)**](https://refactoring.guru/design-patterns/composite) :speech_balloon:

- Why you picked this pattern and what feature you will implement with it?
   
  -  **We want to be able to keep track of players’ information instead of just having them play with a new account every time. Everyone who plays a game with you would automatically become your friend. And being friends with each other, the win rates information is visible to the community to allows everyone is on the same page.**
    

-   What problem you anticipate encountering when implementing your project that you will solve using the design pattern?
    

    - **When storing a vector with string in the player object, it is rather difficult to keep track of those players’ current win rates, and updated win rates. We want the player can view their friend’s dynamic information including their win rates.**
    

-   Why the chosen design pattern will lead to a good solution to that problem?
    

    -  **By using the composite pattern, we are able to store a pointer* vector of player object inside each player. That allows us to dynamically calculate the win rates of every player in the friend list. Alone you can compare if you are improving by seeing how other players improve their win rates.** 


## Phase II
## Class Diagram 
![Final Project 2_16 - UML Class (2)](https://user-images.githubusercontent.com/77028662/108160982-f4415c80-709e-11eb-9d24-f5c3ba7e24b0.jpeg)


 <br />
Class Description: 

- In this program, there is a class named Game. In the Game class, both players, the start and end time, game progress, and vector are established. Game Class also aggregates the three classes spot, board, and move which together initialize the board, determine locations, and check the validity of moves. The Board list inherits from the game class and will be the class that manages the save and load functions of our program. It saves the board in a vector of boards when saved, can delete all games, and load a specific board.

- On the other hand, We also have the class Player, which will determine the player side, type of player, meanwhile, each player stores an input a name and level, have a stored win counter and total game counter. Also, each player has a vector list of the players. This allows the function to dynamically calculate the win rates for each player stored in the vector list. We use addFriend and emptyFriendList functions to push and empty the vector. And Boolean function to determine if the player is an actual human or AI. In the future, we might add functions that assign a level to each player base on their win rates. There are two classes that inherit from it, HumanPlayer and ComputerPlayer, and by doing this we would be able to understand if the player is a real person or not. By doing so we can implement auto movement inside the AI class, doing this would also make sure no HumanPlayer can use the programmed algorithm (To avoid game cheat).

- The next class, Pieces, inherits from the Game class. In this class, the color of the pieces is set, movement is determined, and the game is able to figure out if a piece has been “defeated” by using the strategy design pattern. Additionally, the six pieces of the chess game, king, queen, rook, bishop, knight, and pawn, each have their own classes that inherit from the Pieces class. In these classes, the specific movement of the unique pieces is established, along with conditional movements. For example, the rook and king being able to “castle” as a unique move in the game.












  <br />
  <br />
  <br />
  <br />
  <br />
  <br />
  <br />
  <br />
  <br />
 
**References:**\
https://refactoring.guru/<br />
https://en.wikipedia.org/wiki/Chess  <br />
https://en.wikipedia.org/wiki/Chess_symbols_in_Unicode  <br />

 


**____________________________________________________________________________________________________________________**
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
