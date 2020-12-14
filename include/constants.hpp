#ifndef CONSTANTS_H
#define CONSTANTS_H

// Includes
#include <string>
#include <vector>
#include <map>

/**
 * @brief Constants.hpp file
 * It contains all constants used in the project Blackjack, such as the index of the enum classes.
 * 
 */
// Card Color
constexpr int   CARD_COLOR_MIN          = 0;
constexpr int   CARD_COLOR_MAX          = 1;

// Card Value
constexpr int           CARD_VALUE_MIN      = 1;
constexpr int           CARD_VALUE_MAX      = 13;
constexpr unsigned int  CARD_VALUE_AS_MIN   = 1;
constexpr unsigned int  CARD_VALUE_AS_MAX   = 11;
constexpr int           CARD_VALUE_TEN      = 10;

// Card Symbol
constexpr int   CARD_SYMBOL_MIN         = 0;
constexpr int   CARD_SYMBOL_MAX         = 3;
constexpr int   CARD_SYMBOL_RED_MIN     = 0;
constexpr int   CARD_SYMBOL_RED_MAX     = 1;
constexpr int   CARD_SYMBOL_BLACK_MIN   = 2;
constexpr int   CARD_SYMBOL_BLACK_MAX   = 3;

// Deck
constexpr unsigned int NUMBER_OF_CARDS_DEFAULT_DECK = 52;

// Game Entities - Deck
constexpr unsigned int NUMBER_OF_CARDS_AT_START = 2;

// The Blackjack game itself - General data
constexpr unsigned int NUMBER_OF_PLAYERS_MAX          = 4;
constexpr unsigned int NUMBER_OF_PLAYERS_MIN          = 1;
constexpr unsigned int NUMBER_OF_LANGUAGES_SUPPORTED  = 2;
constexpr unsigned int CASINO_DEALER_HAND_VALUE_LIMIT = 17;
constexpr unsigned int MAX_VALUE_TO_WIN               = 21;
constexpr unsigned int BLACKJACK_ACE_VALUE            = 50; // in theory, it's 21, but I set it at 50 so there is no ambiguity it was a BJ and not a combination leading to 21
const std::string      YES                            = "Y";

// The Blackjack game itself - Map keys
const std::string KEY_REMOVE_PLAYERS        = "K_REMOVE_PLAYERS";
const std::string KEY_ADD_PLAYERS           = "K_ADD_PLAYERS";
const std::string KEY_QUESTION_TITLE        = "K_Q_TITLE";
const std::string KEY_INPUT_TITLE           = "K_TITLE";
const std::string KEY_INPUT_NAME            = "K_NAME";
const std::string KEY_INPUT_COINS           = "K_COINS";
const std::string KEY_PLAYERS_INGAME        = "K_PLAYERS_INGAME";
const std::string KEY_INPUT_PLAYERS_INDEX   = "K_INPUT_PLAYERS_INDEX";
const std::string KEY_INVALID_INPUT         = "K_INVALID_INPUT";
const std::string KEY_RETRY                 = "K_RETRY";

// The Blackjack game itself - Sentences from the Game to the UI
const std::vector<std::string> LANGUAGES {"FR", "EN"};
const std::map<std::string, const std::vector<std::string> > SENTENCES {
    { KEY_REMOVE_PLAYERS,
        {"Voulez-vous retirer des joueurs de la partie ? Si oui, appuyez sur la touche Y, sinon appuyez sur n'importe quelle touche",
         "Would you like to remove players from the game ? If yes, press the Y key, otherwise press any key"}
    },

    { KEY_ADD_PLAYERS,
        {"Voulez-vous ajouter de nouveaux joueurs à la partie ? Si oui, appuyez sur la touche Y, sinon appuyez sur n'importe quelle touche",
         "Would you like to add new players to the game ? If yes, press the Y key, otherwise press any key"}
    },

    { KEY_QUESTION_TITLE,
        {"Avez-vous un titre ? Si oui, appuyez sur la touche Y, sinon appuyez sur n'importe quelle touche",
         "Do you have a title ? If yes, press the Y key, otherwise press any key"}
    },

    { KEY_INPUT_TITLE,
        {"Entrez votre titre",
         "Enter your title"}
    },

    { KEY_INPUT_NAME,
        {"Entrez votre nom",
         "Enter your name"}
    },

    { KEY_INPUT_COINS,
        {"Entrez le nombre de jetons que vous souhaitez",
         "Enter the number of coins you would like"}
    },

    { KEY_PLAYERS_INGAME,
        {"Les joueurs en jeu sont :",
         "Ingame players are :"}
    },

    { KEY_INPUT_PLAYERS_INDEX,
        {"Entrez le numero du joueur à retirer de la partie",
         "Enter the number of the player to be removed from the game"}
    },

    { KEY_INVALID_INPUT,
        {"Saisie invalide",
         "Invalid input"}
    },

    { KEY_RETRY,
        {"Voulez-vous rééssayer ? Si oui, appuyez sur la touche Y, sinon appuyez sur n'importe quelle touche",
         "Do you want to try again ? If yes, press the Y key, otherwise press any key"}
    }
};

#endif // CONSTANTS_H