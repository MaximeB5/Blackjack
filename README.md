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

# Program Arguments :
	-	Argument 1 : Language of the game. The options are : "EN", "en" "En" "eN" or "FR", "fr", "fR", "Fr". The default language is "English".
	-	Argument 2 : Game mode. The options are : "DD" (for DefaultDeck), "JC" (for JohnCena). /!\ JC isn't fully implemented and thus not working.
	-	Argument 3 : Name of the Casino Dealer. Set the name you want, without spaces. The default name is "Casino Dealer"

----------------------------------------------------------------------------------------------------

# HOW TO CUSTOMIZE :
It is very easy.

All classes are working well together to help you to customize this project quickly and easily, here are the "main" steps to follow :

	-	Step 1 : Go in HumanPlayer.cpp and implement your own Play() method. Then do the same for CasinoDealer::Play if you want it to play differently that the default case already implemented.


	-	Step 2 : It might be long at the first view, but the code already implemented will greatly help you to do it quickly : it's now time to customize your own GameBoard::Play method. FYI, this method IS the one called in the main and it MUST describes ONE TURN ONLY of your game.


	-	Optional Step - New Language : Let's say you would like to add your own language to the game, well, it's pretty easy as well ! Add all of your translations into the constants.hpp file (check the big std::map that contains all messages displayed, there are already 2 langages ingame so it'll be easy for you to add your own). Add to the Langage enum your new Language, then, set the langage parameter in the GameBoard constructor when the instance is created in the main and you're done.


	-	Optional Step - New GameMode : pretty easy as well, add your own mode in the DeckSpecification enum, and do Steps 1 and 2. Do not forget to add in constants.hpp some constants such as BLACKJACK_ACE_VALUE = 50 for example if you need some "super cards" or if you want to add special moves or effects in game. After implementing this, add into the Deck constructor how you want to build your deck if it differs from a default deck.
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

  - CODE :

			-	OPEN POINTS :
				-	None.
			
			-	When the great cleaning will come, i.e. when the v1.1 will fully work (which is not so far from now)... Let's use ONE FUCKING SYNTAX and not one for interface functions, another one for class methods, etc. I want to see the whole world on the same step. After that, let's solve all syntax bugs lmao. And again after that, let's read the whole codes to increase the global readability. -> If I don't understand at the first sight, THEN IT NEEDS COMMENTS TO UNDERSTAND IT LATER. Hell yeah bitches ! 
  
  - DOC :

			-	Create a Class Diagram with the pictures in documentation : TODO : from Deck to the end. NOTA : this is killing me, I don't want to do it.
			-	Add graphs representing the evolution of the score for wins and defeats.

  - TESTS :

			-	Unit tests to do : GameBoard (ONGOING) if possible.
			-	ONGOING ISSUES : None.
    
