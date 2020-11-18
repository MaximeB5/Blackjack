#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// My Includes
#include "../include/card.hpp"
#include "../include/casinodealer.hpp"
#include "../include/coins.hpp"
#include "../include/deck.hpp"
#include "../include/deckexception.hpp"
#include "../include/magic_enum.hpp"


/**
 * @brief Test Case for the Card class
 * We'll have to test the different constructors and overload operators, in addition to the getters.
 * So first, let's build a Card, then test the getters, and after this step,
 * we can test other constructors and the operators to check if the getters are still working.
 * Note : Operators are implicitly check by the constructors 2 and 3 (they have the same implementation that constructors Card & and Card &&).
 */
TEST_CASE("Test Case for the Card class", "[MyTag]") {
    WARN("Start of the test case for the Card class");

    // Constructor 1
    Card c{CardColor::Red, CardSymbol::Clover, CardValue::As};

    REQUIRE(c.getCardColor()  == CardColor::Red);
    REQUIRE(c.getCardSymbol() == CardSymbol::Clover);
    REQUIRE(c.getCardValue()  == CardValue::As);

    // Constructor 2 - const
    const Card constCard{CardColor::Black, CardSymbol::Pike, CardValue::Two};
    Card cc{constCard};

    REQUIRE(cc.getCardColor()  == CardColor::Black);
    REQUIRE(cc.getCardSymbol() == CardSymbol::Pike);
    REQUIRE(cc.getCardValue()  == CardValue::Two);

    // Constructor 2
    Card ccc{c};

    REQUIRE(ccc.getCardColor()  == CardColor::Red);
    REQUIRE(ccc.getCardSymbol() == CardSymbol::Clover);
    REQUIRE(ccc.getCardValue()  == CardValue::As);

    // Constructor 3
    Card cccc{std::move(c)};

    REQUIRE(cccc.getCardColor()  == CardColor::Red);
    REQUIRE(cccc.getCardSymbol() == CardSymbol::Clover);
    REQUIRE(cccc.getCardValue()  == CardValue::As);

    WARN("End of the test case for the Card class");
}


/**
 * @brief Test Case for the CasinoDealer class
 * 
 */
TEST_CASE("Test Case for the CasinoDealer class", "[MyTag]") {
    // TODO after implementing the class.
    WARN("Start of the test case for the CasinoDealer class");
    WARN("! TODO !");
    WARN("End of the test case for the CasinoDealer class");
}


/**
 * @brief Test Case for the Coins class
 * We test all methods and check it throws when it should.
 */
TEST_CASE("Test Case for the Coins class", "[MyTag]") {
    WARN("Start of the test case for the Coins class");

    Coins c{5};
    REQUIRE(c.maxValue() == UINT_MAX);
    REQUIRE(c.getValue() == 5);

    c.addValue(1);
    REQUIRE(c.getValue() == 6);
    REQUIRE_THROWS_AS(c.addValue(UINT_MAX), CoinsException);

    c.setValue(2);
    REQUIRE(c.getValue() == 2);
    REQUIRE_THROWS_AS(c.removeValue(3),     CoinsException);
    REQUIRE_THROWS_AS(c.setValue(UINT_MAX), CoinsException);

    WARN("End of the test case for the Coins class");
}



/**
 * @brief Test Case for the Deck class
 * The Deck class can be used in different ways according to the owner.
 * It can be the global deck of the game, just like the player hand. We do need to test both uses.
 * This can be check by using the different constructors defined.
 * 
 * Note : for a deck of the game use, we'll test the only DeckSpecification implemented at this time : Default (18/11/2020)
 * 
 */
TEST_CASE("Test Case for the Deck class", "[MyTag]") {
    WARN("Start of the test case for the Deck class");

    // Constructor 1
    Deck gameDeck{DeckSpecification::DefaultDeck};
    
    // Give a Card
    Card c{gameDeck.Give_a_Card()};

    std::string msg  = "Give_a_Card() gave the Card ";
    auto card_color  = magic_enum::enum_name<CardColor>(c.getCardColor());
    msg.append(card_color); msg.append(" ");
    auto card_symbol = magic_enum::enum_name<CardSymbol>(c.getCardSymbol());
    msg.append(card_symbol); msg.append(" ");
    auto card_value  = magic_enum::enum_name<CardValue>(c.getCardValue());
    msg.append(card_value);

    WARN(msg);

    // Drop a Specific Card (we'll try with the previously given card) + Add a Card
    // 1st, it should throw, and after adding it into the deck, we should retrieve it
    auto color  = magic_enum::enum_cast<CardColor>(card_color);
    auto symbol = magic_enum::enum_cast<CardSymbol>(card_symbol);
    auto value  = magic_enum::enum_cast<CardValue>(card_value);

    Card cc{color.value(), symbol.value(), value.value()};
    REQUIRE_THROWS_AS(gameDeck.Drop_a_Specific_Card(cc), DeckException);

    gameDeck.Add_a_Card(cc);
    REQUIRE_NOTHROW(gameDeck.Drop_a_Specific_Card(cc));

    // Shuffle
    WARN("Shuffle - if we shuffle, the cc Card should not be at the end of the deck (but if we're unlucky it can be, and so the test will fail lmao)");
    gameDeck.Shuffle();
    Card ccc{gameDeck.Give_a_Card()};
    bool result{   ccc.getCardColor()  == cc.getCardColor()
                && ccc.getCardSymbol() == cc.getCardSymbol()
                && ccc.getCardValue()  == cc.getCardValue()  };
    REQUIRE_FALSE(result);

    // Reset
    gameDeck.Reset();
    REQUIRE_THROWS_AS(gameDeck.Drop_a_Specific_Card(cc), DeckException);

    // Create a new Deck
    REQUIRE_THROWS_AS(gameDeck.Create_a_new_Deck(DeckSpecification::JohnCena), DeckException);

    // Constructor 2
    Deck playerHand{NUMBER_OF_CARDS_AT_START};

    WARN("End of the test case for the Deck class");
}

/**
 * @brief Test Case for the GameBoard class
 * 
 */
TEST_CASE("Test Case for the GameBoard class", "[MyTag]") {
    // TODO after implementing the class.
    WARN("Start of the test case for the GameBoard class");
    WARN("! TODO !");
    WARN("End of the test case for the GameBoard class");
}