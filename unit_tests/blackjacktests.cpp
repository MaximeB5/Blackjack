#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// My Includes
#include "../include/card.hpp"
#include "../include/casinodealer.hpp"
#include "../include/coins.hpp"

/**
 * @brief Test Case for the Card class
 * We'll have to test the different constructors and overload operators, in addition to the getters.
 * So first, let's build a Card, then test the getters, and after this step,
 * we can test other constructors and the operators to check if the getters are still working.
 * Note : Operators are implicitly check by the constructors 2 and 3 (they have the same implementation that constructors Card & and Card &&).
 */
TEST_CASE("Test Case for the Card class", "[MyTag]") {
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
}


/**
 * @brief Test Case for the CasinoDealer class
 * 
 */
TEST_CASE("Test Case for the CasinoDealer class", "[MyTag]") {
    // TODO after implementing the class.
    REQUIRE(1 == 1);
}


/**
 * @brief Test Case for the Coins class
 * We test all methods and check it throws when it should.
 */
TEST_CASE("Test Case for the Coins class", "[MyTag]") {
    Coins c{5};
    REQUIRE(c.maxValue() == UINT_MAX);
    REQUIRE(c.getValue() == 5);

    c.addValue(1);
    REQUIRE(c.getValue() == 6);
    REQUIRE_THROWS_AS(c.addValue(-1),       CoinsException);
    REQUIRE_THROWS_AS(c.addValue(UINT_MAX), CoinsException);

    c.setValue(2);
    REQUIRE(c.getValue() == 2);
    REQUIRE_THROWS_AS(c.setValue(-1),       CoinsException);
    REQUIRE_THROWS_AS(c.setValue(UINT_MAX), CoinsException);
}
