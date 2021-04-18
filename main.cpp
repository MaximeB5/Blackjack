// My Includes
#include "include/gameboard.hpp"
#include "include/constants.hpp"

// Indludes
#include <algorithm>
#include <string> 

// Defines
    // None.

// Forward declarations for the main
Language          param_arg_language          (char** argv);
DeckSpecification param_arg_game_mode         (char** argv);
Name              param_arg_casino_dealer_name(char** argv);


int main(int argc, char *argv[])
{
    std::cout << "----- Welcome in my Blackjack program -----" << "\n\n";

    // Create the game board
    std::unique_ptr<GameBoard> GB;

    if( argc == 2 )
    {
        GB = std::make_unique<GameBoard>( param_arg_language(argv) );
    }
    else if( argc == 3 )
    {
        GB = std::make_unique<GameBoard>( param_arg_language(argv), param_arg_game_mode(argv) );
    }
    else if( argc == 4 )
    {
        GB = std::make_unique<GameBoard>( param_arg_language(argv), param_arg_game_mode(argv), param_arg_casino_dealer_name(argv) );
    }
    else
    {
        GB = std::make_unique<GameBoard>();
    }

    // Game loop
    while( GB->Play() )
    {
        // Add here some actions for the logs (get all data and metadata from GameBoard getters. FYI the getters you need have to be implemented)
    }

    std::cout << "----- Exiting Blackjack program -----" << "\n";

    return 0;
}


/**
 * @brief get argv[1] from the main and return the matching language. In case of error and as default, the language will be Language::English.
 * 
 * @param argv 
 * @return Language 
 */
Language param_arg_language(char** argv)
{
    // Get the language parameter as a string
    auto param = std::string{ argv[1] };

    // Set the strig parameter to uppercase
    transform( param.begin(), param.end(), param.begin(), ::toupper );

    // Check the parameter matches the vector of languages
    auto i{0U};
    for( auto it{LANGUAGES.begin()}; it != LANGUAGES.end(); ++it, ++i )
    {
        if( *it == param )
        {
            // Careful, this part must be conform to the LANGUAGES vector in constants.hpp and Languages in languages.hpp
            switch( i )
            {
                case 0:
                    return Language::French;
                break;

                case 1:
                default:
                    return Language::English;
                break;
            }
        }
    }

    // If no match in the for loop, English is the default language
    return Language::English;
}


/**
 * @brief get argv[2] from the main and return the matching language. In case of error and as default, the language will be Language::English.
 * 
 * @param argv 
 * @return DeckSpecification 
 */
DeckSpecification param_arg_game_mode(char** argv)
{
    // Get the language parameter as a string
    auto param = std::string{ argv[1] };

    // Set the strig parameter to uppercase
    transform( param.begin(), param.end(), param.begin(), ::toupper );

    // Check the parameter matches the vector of languages
    auto i{0U};
    for( auto it{GAME_MODES.begin()}; it != GAME_MODES.end(); ++it, ++i )
    {
        if( *it == param )
        {
            // Careful, this part must be conform to the GAME_MODES vector in constants.hpp and DeckSpecification in deckspecification.hpp
            switch( i )
            {
                case 1:
                    return DeckSpecification::JohnCena;
                break;

                case 0:
                default:
                    return DeckSpecification::DefaultDeck;
                break;
            }
        }
    }

    // If no match in the for loop, DefaultDeck is the default language
    return DeckSpecification::DefaultDeck;
}


/**
 * @brief get argv[3] from the main and return the matching Name for the Casino Dealer
 * I don't check errors or whatsoever retarded inputs.
 * 
 * @param argv 
 * @return Name 
 */
Name param_arg_casino_dealer_name(char** argv)
{
    return Name{ argv[3] };
}
