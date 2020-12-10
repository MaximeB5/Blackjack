# Blackjack
This project is to develop a Blackjack game, casino light version.

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
  - CODE :

			-	Continue the implementation of CasinoDealer::Play
			-	Implement the GameBoard class. --> ONGOING, let's continue at Step 4
			-	Add Play() method from IPlay (with a returned value and arguments if needed) in GameBoard (ONGOING), HumanPlayer (TODO) and CasinoDealer (ONGOING)
			-	OPEN POINTS : None.
  
  - DOC :

			-	Create a Class Diagram with the pictures in documentation.
			-	Add graphs representing the evolution of the score for wins and defeats.

  - TESTS :

			-	Unit tests to do : GameBoard (ONGOING).
			-	Test the new constructors of HumanPlayer with unsigned int coinsAtStart
			-	Test the Play() method of HumanPlayer, CasinoDealer and GameBoard
			-	ONGOING ISSUES : None.
    
