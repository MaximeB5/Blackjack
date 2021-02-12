# Blackjack
This project is to develop a Blackjack game, casino light version.
The C++ version is C++17. Would be great to go to C++20 with std::osyncstream(std::cout) for the v1.1

The main key points of the different versions are the following :

	-	1.1 : The game itself without special moves, on terminal.	-> WE'RE HERE FOLKS
	-	1.2 : Add a dedicated log system (no data saved).
	-	1.3 : Add a database that will, besides the log system, save all other data and meta data (bank, players, etc).
	-	1.4 : Add a C++ GUI (Qt).
	-	1.5 : Add a data extraction functionality through an external file such as PDF or other.

----------------------------------------------------------------------------------------------------

# BUILD :
From root : cd build && cmake .. && make && cd .. && cd bin/ && ./Blackjack

Then, after implementing some stuff :

From the bin folder : cd .. && cd build/ && cmake .. && make && cd .. && cd bin/ && ./Blackjack

----------------------------------------------------------------------------------------------------

# GIT :
"git pull"			update the local repo


"git add" add files and/or folders

"git add -A" stages all changes

"git add ." stages new files and modifications, without deletions

"git add -u" stages modifications and deletions, without new files


"git commit -m "message""	commit with the message


"git push" push on the repo online

----------------------------------------------------------------------------------------------------

# TODO :

  - PROGRAM :
  
			-	Add program arguments in order to set the GameBoard constructor arguments and make the program more generic to use

  - CODE :

			-	GameBoard::Play -> add in Step 1 after checkPlayers a check if players are ready or if they want to skip or leave
			-	GameBoard::Play -> add a return value (bool) if no player in game && exit program so it can exit the main loop in main.cpp and avoid memory leaks)
			-	GameBoard::Play -> checkPlayers -> If answer != Y, a turn is launched. It has to loop if no players e.g. 
			-	OPEN POINTS : If a player wants to skip his next turn, how to put it back into the turn t+2 ? -> maybe change it for something like we ask at the beginning of each turn ?
  
  - DOC :

			-	Create a Class Diagram with the pictures in documentation.
			-	Add graphs representing the evolution of the score for wins and defeats.

  - TESTS :

			-	Unit tests to do : GameBoard (ONGOING) if possible.
			-	ONGOING ISSUES : None.
    
