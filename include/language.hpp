#ifndef LANGUAGE_H
#define LANGUAGE_H

/**
 * @brief enum class Language : int
 * It contains the languages for which the game messages are implemented in constants.hpp (see the map SENTENCES).
 * 
 * CAUTION : The values set for each language here must be in accordance with the order of the languages in LANGUAGES in constants.hpp.
 * 
 */
enum class Language : int {
    French  = 0,
    English = 1
};

#endif // LANGUAGE_H