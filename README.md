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

--The Project itself is interesting because it is not a simple chess game. We want to build a game that allows gamers to have a rich community where they could join the same group. Play games together, or even play matches in a Tournament game. We also introduce the winrate, a mechanism like KDA which dynamically calculates your win rate. By simply keeping on track your win rate, you would be able to tell how much you are improving on chess.

 - (1) A move is possible 🚶
 - (2) The importance of the king to prolong the game so that it does not end quickly 👑


<br />

**Languages/Tools/technologies**🧰
   * C++


**Input/output**:robot: 
  * Keyboard⌨
  * Monitor💻

**Design Patterns**🔋


[**Strategy (Behavioral Pattern)**](https://refactoring.guru/design-patterns/strategy) :speech_balloon:

- Why you picked this pattern and what feature you will implement with it?
   
  -  **We chose this pattern because it will allow us to implement a movement for each unique piece while maintaining organization and avoiding redundant code.**
    

-   What problem you anticipate encountering when implementing your project that you will solve using the design pattern?
    

    -  **Chess has six unique pieces, each with different movement patterns. Since we are not chess masters, It would not be easy to implement all the possible patterns and rules for chess in one go.**
    

-   Why the chosen design pattern will lead to a good solution to that problem?
    

    -   **Utilizing the Strategy pattern would allow us to construct a base Move_valid class and divide each movement algorithm into separate strategies. This allows us to avoid having a massive if-then statement on the board.cpp itself. Also, by doing this, it enables us to easily change the gamerules while having little effect on other files.**

[**Composite Pattern (structural design pattern)**](https://refactoring.guru/design-patterns/composite) :speech_balloon:

- Why you picked this pattern and what feature you will implement with it?
   
  -  **We want to be able to keep track of players’ information instead of just having them play with a new account every time. We also want to let ComputerPlayer and HumanPlayer be friends. Allowing them to have ranks base on their win rate. Or even join the same team for Tournament**
    

-   What problem you anticipate encountering when implementing the project that you will solve using the design pattern?
    

    - **When storing a vector with string in the player object, it is rather difficult to keep track of those players’ current win rates, and updated win rates. We want that a design pattern that could store both ComputerPlayer and HumanPlayer into a single List. Allowing us to get player information easily using a pointer.**
    

-   Why the chosen design pattern will lead to a good solution to that problem?
    

    -  **By using the composite pattern, we are able to store all children inherit from the Player class to be store in a single class. Which is the PlayerList class. Not only this enables us to merge Human and Computer Player, but we could also even store a list inside a list. This would allow us to make Tournament possible and easier to maintain codes** 

[**Facotry Pattern (creational design pattern)**](https://refactoring.guru/design-patterns/factory-method/cpp/example#:~:text=Method%20%2F%20C%2B%2B-,Factory%20Method%20in%20C%2B%2B,constructor%20call%20(%20new%20operator).) :speech_balloon:

- Why you picked this pattern and what feature you will implement with it?
   
  -  **While doing the board class, we found that it is extremely redundant to check for the current position's piece. Since we are creating can_move object base on that dynamic data we picked this Facotry Pattern **
    

-   What problem you anticipate encountering when implementing the project that you will solve using the design pattern?
    

    - **To dynamically creates new objects that inherent from the same base class and do almost the same functionality to it would take us many redundant codes.**
    

-   Why the chosen design pattern will lead to a good solution to that problem?
    

    -  **By using the Factory Pattern, we are able to reduce all those messy if-then statements into one in board.cpp. This allows us to debug much easier. Not only that, if we want to add something special to the game, we do not have to worry about changing the board.cpp** 




## Phase II
## Class Diagram 
![Final Project 2_16 - UML Class](https://user-images.githubusercontent.com/77028662/110617388-8098e980-814a-11eb-9f96-a770020aed80.jpeg)



 <br />
Class Description: 

- The program could be divide into two main sections. 1)community functions; 2) gameplays 

- In the community functions section, we have a master abstract Player class that holds information for a basic player including name and level, winrate. Both HumanPlayer and ComputerPlayer is a type of player, so they inherent form it naturally with different function like enabling ComputerPlayer to modify their winrate to allow easy testing. On top of that, we also have a PlayerList which then stores any object inherent from Player Class, that being said, it could store a list of a list. And the recursive function inside would handle the print list and pick player correctly. This allows us to an easy setup if we want to do a Tournament in the future.

- In the gameplays section, it is divided into a few classes. We have a board class that basically holds the information of a game and two players' information. We also have CanMove class and its many sub_class to the corresponding game rules for each piece in the chess game. Doing this in a strategy pattern fashion allows us to easily change their behavior and keep those codes in the same place. On top of the Strategy Pattern, we also introduced a factory partner that response to the board and return the correct canMove object. With the spot class, we are able to store pieces as char instead of a custom object.  

- The game itself is an interface with the user. Allowing them to play the game.


## Phase III (Meeting With TA; Done)


 ## Final deliverable
 
 * Plan one more sprint record on the Kanban board.  (Done)
 
 ## Screenshots
 Screenshots of the input/output after running your application
![Normal GamePlay 1V1](https://user-images.githubusercontent.com/77028662/110723176-803f3380-81c8-11eb-9830-961b4f63be4b.png)
![1V1 Game Win](https://user-images.githubusercontent.com/77028662/110723178-80d7ca00-81c8-11eb-85fd-a3db7c27c5c6.png)
![Print Rules](https://user-images.githubusercontent.com/77028662/110723181-80d7ca00-81c8-11eb-837c-5e82773d70cb.png)
![Exit Game](https://user-images.githubusercontent.com/77028662/110723182-80d7ca00-81c8-11eb-932e-f4e13bb3c0a0.png)
![3PLAYERS](https://user-images.githubusercontent.com/77028662/110723183-81706080-81c8-11eb-8c24-af8abcfce077.png)
Starting a game and Moving

<img width="549" alt="Screen Shot 2021-03-10 at 5 41 40 PM" src="https://user-images.githubusercontent.com/77082321/110724435-9d750180-81ca-11eb-9fb3-1d0a2546fd78.png">
Swaping sides and moving 

<img width="549" alt="Screen Shot 2021-03-10 at 5 41 40 PM" src="https://user-images.githubusercontent.com/77082321/110724459-aa91f080-81ca-11eb-89d0-ba365d29f2e9.png">
Resetting the Board

<img width="186" alt="Screen Shot 2021-03-10 at 5 52 36 PM" src="https://user-images.githubusercontent.com/77082321/110724616-f5ac0380-81ca-11eb-888a-b0d6db63a9a3.png">

Tournament Mode:
![RANK2](https://user-images.githubusercontent.com/77028662/110724581-e2993380-81ca-11eb-9d06-184102896e3b.png)
![RANK1](https://user-images.githubusercontent.com/77028662/110724582-e2993380-81ca-11eb-8fb9-7ec05d3ee02a.png)


 
 
 ## Installation/Usage
 Instructions on installing and running your application
 The game is design to simply allow users to integrate into another program. Just simply include "board.hpp" and "Game.h" Make a new Game* f = new Game();
  and call f->PrintMenu(f), it would handle the game internally. Remember to delete f once you finish the game.
  
 <img width="300" alt="Screen Shot 2021-03-10 at 5 52 36 PM" src="https://user-images.githubusercontent.com/77028662/110724628-fd6ba800-81ca-11eb-8899-f3f28deb2278.png">
 
 
 ## Testing
 How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.


-We understood how the code should have worked, so at each step for the larger classes, we tested absolutely everything. Using unit tests we understood what the outcome of our program would be so we accounted for those in our unit tests. 

-We heavily used unit_test to ensure everything was working properly as it should. We gave each implementation a test file to individually test each file. Not only that, but we also gave the game a special debug function which allowed us to make one of the players instantly win, so we can better debug the functionalities about Player class, for example, how to keep track of their win-rate or rank.

-A total of 40 different tests shows that the program meets the standard and ready to be pre-released.  

 ![Testing](https://user-images.githubusercontent.com/77028662/110723173-7fa69d00-81c8-11eb-8b4c-39f5bf4ed2e8.png)
 ![48](https://user-images.githubusercontent.com/77028662/110725803-0e1d1d80-81cd-11eb-9dc2-28177b316816.png)
![New test](https://user-images.githubusercontent.com/77028662/110724473-b4b3ef00-81ca-11eb-9355-0dc8e09fff2a.png)
![New Test](https://media.discordapp.net/attachments/804492870441762817/819395155730628618/Screen_Shot_2021-03-10_at_6.22.23_PM.png?width=1210&height=915)



**References:**\
https://refactoring.guru/<br />
https://en.wikipedia.org/wiki/Chess  <br />
https://en.wikipedia.org/wiki/Chess_symbols_in_Unicode  <br />
