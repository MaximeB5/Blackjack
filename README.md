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
Go to the build folder, then write in the terminal at this location : cmake .. && make

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
			-	Infinite loop at GameBoard::Play -> blocked in checkPlayers (I can only add or remove players but not play lmao)

  - CODE :

			-	GameBoard::Play -> add in Step 1 after checkPlayers a check if players are ready or if they want to skip or leave
			-	OPEN POINTS : If a player wants to skip his next turn, how to put it back into the turn t+2 ?
  
  - DOC :

			-	Create a Class Diagram with the pictures in documentation.
			-	Add graphs representing the evolution of the score for wins and defeats.

  - TESTS :

			-	Unit tests to do : GameBoard (ONGOING).
			-	Test the new constructors of HumanPlayer with unsigned int coinsAtStart
			-	Test HumanPlayer::getHandValue
			-	Test the Play() method of HumanPlayer, CasinoDealer and GameBoard
			-	ONGOING ISSUES : None.
    
