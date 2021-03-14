# Blackjack
This project is to develop a Blackjack game, casino light version.
The C++ version is C++17. Would be great to go to C++20 with std::osyncstream(std::cout) for the v1.1

The main key points of the different versions are the following :

	-	1.1 : The game itself without special moves, on terminal.
	-	1.2 : Add a dedicated log system (no data saved).	-> WE'RE HERE FOLKS
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

			-	GameBoard::Play -> add a return value (bool) if no player in game && exit program so it can exit the main loop in main.cpp and avoid memory leaks)
			-	OPEN POINTS :
				-	Add a detector when Casino Dealer went over 21, it has to lose
				-	I don't remember if Blacjjack is explicitly specified for the Player -> TBC and if not, let's set it
			
			-	When the great cleaning will come, i.e. when the v1.1 will fully work (which is not so far from now)... Let's use ONE FUCKING SYNTAX and not one for interface functions, another one for class methods, etc. I want to see the whole world on the same step. After that, let's solve all syntax bugs lmao. And again after that, let's read the whole codes to increase the global readability. -> If I don't understand at the first sight, THEN IT NEEDS COMMENTS TO UNDERSTAND IT LATER. Hell yeah bitches ! 
  
  - DOC :

			-	Create a Class Diagram with the pictures in documentation.
			-	Add graphs representing the evolution of the score for wins and defeats.

  - TESTS :

			-	Unit tests to do : GameBoard (ONGOING) if possible.
			-	ONGOING ISSUES : None.
    
