#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// My Includes
#include "../include/card.hpp"
#include "../include/cardcolor.hpp"
#include "../include/cardsymbol.hpp"
#include "../include/cardvalue.hpp"
#include "../include/casinodealer.hpp"
#include "../include/coins.hpp"
#include "../include/coinsexception.hpp"
#include "../include/constants.hpp"
#include "../include/deck.hpp"
#include "../include/deckexception.hpp"
#include "../include/deckspecification.hpp"
#include "../include/gameboard.hpp"
#include "../include/humanplayer.hpp"
#include "../include/magic_enum.hpp"
#include "../include/name.hpp"
#include "../include/playertag.hpp"
#include "../include/score.hpp"
#include "../include/title.hpp"
#include "../include/wallet.hpp"


/**
 * @brief Test Case for the Card class
 * We'll have to test the different constructors and overload operators, in addition to the getters.
 * So first, let's build a Card, then test the getters, and after this step,
 * we can test other constructors and the operators to check if the getters are still working.
 * Note : Operators are implicitly check by the constructors 2 and 3 (they have the same implementation that constructors Card & and Card &&).
 */
TEST_CASE("Test Case for the Card class", "[CARD]") {
    WARN("Start of the test case for the Card class");

    // Constructor 1
    Card c{ CardColor::Red, CardSymbol::Clover, CardValue::As };

    REQUIRE(c.getCardColor()  == CardColor::Red);
    REQUIRE(c.getCardSymbol() == CardSymbol::Clover);
    REQUIRE(c.getCardValue()  == CardValue::As);

    // Constructor 2 - const
    const Card constCard{ CardColor::Black, CardSymbol::Pike, CardValue::Two };
    Card cc{ constCard };

    REQUIRE(cc.getCardColor()  == CardColor::Black);
    REQUIRE(cc.getCardSymbol() == CardSymbol::Pike);
    REQUIRE(cc.getCardValue()  == CardValue::Two);

    // Constructor 2
    Card ccc{ c };

    REQUIRE(ccc.getCardColor()  == CardColor::Red);
    REQUIRE(ccc.getCardSymbol() == CardSymbol::Clover);
    REQUIRE(ccc.getCardValue()  == CardValue::As);

    // Constructor 3
    Card cccc{ std::move(c) };

    REQUIRE(cccc.getCardColor()  == CardColor::Red);
    REQUIRE(cccc.getCardSymbol() == CardSymbol::Clover);
    REQUIRE(cccc.getCardValue()  == CardValue::As);

    WARN("End of the test case for the Card class");
}


/**
 * @brief Test Case for the CasinoDealer class
 * 
 */
TEST_CASE("Test Case for the CasinoDealer class", "[CASINO_DEALER]") {
    // TODO after implementing the class.
    WARN("Start of the test case for the CasinoDealer class");
    WARN("! TODO !");
    WARN("End of the test case for the CasinoDealer class");
}


/**
 * @brief Test Case for the Coins class
 * We test all methods and check it throws when it should.
 */
TEST_CASE("Test Case for the Coins class", "[COINS]") {
    WARN("Start of the test case for the Coins class");

    Coins c{ 5 };
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
TEST_CASE("Test Case for the Deck class", "[DECK]") {
    WARN("Start of the test case for the Deck class");

    // Constructor 1
    Deck gameDeck{ DeckSpecification::DefaultDeck };
    
    // Give a Card
    Card c{ gameDeck.Give_a_Card() };

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
    WARN("Shuffle - if we shuffle, the cc Card should not be at the end of the deck (but if we're unlucky it can be, and so the test will fail lmao, but it's normal don't worry ahah)");
    gameDeck.Add_a_Card(cc);
    gameDeck.Shuffle();
    Card ccc{ gameDeck.Give_a_Card() };
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
    Deck playerHand{ NUMBER_OF_CARDS_AT_START };

    WARN("End of the test case for the Deck class");
}


/**
 * @brief Test Case for the GameBoard class
 * 
 */
TEST_CASE("Test Case for the GameBoard class", "[GAMEBOARD]") {
    // TODO after implementing the class.
    WARN("Start of the test case for the GameBoard class");
    WARN("! TODO !");
    WARN("End of the test case for the GameBoard class");
}


/**
 * @brief Test Case for the HumanPlayer class
 * 
 */
TEST_CASE("Test Case for the HumanPlayer class", "[HUMAN_PLAYER]") {    
    WARN("Start of the test case for the HumanPlayer class");
    
    // Preliminary stuff
    PlayerTag   plTag1      { Name{ "The Great Name Player 1" } };
    PlayerTag   plTag2      { Title{ "The Great Title 2" }, Name{ "The Great Name Player 2" } };
    Name        plName3     { "The Great Name Player 3" };
    Title       plTitle4    { "The Great Title 4" };
    Name        plName4     { "The Great Name Player 4" };
    
    auto gameDeck = std::make_shared<Deck>(DeckSpecification::DefaultDeck);

    // Constructors
    HumanPlayer player1 { plTag1, gameDeck };
    HumanPlayer player2 { plTag2, gameDeck };
    HumanPlayer player3 { plName3, gameDeck};
    HumanPlayer player4 { plTitle4, plName4, gameDeck};

    auto uptrPlayer1 = std::make_unique<HumanPlayer>(plTag1, gameDeck);
    auto uptrPlayer2 = std::make_unique<HumanPlayer>(plTag2, gameDeck);
    auto uptrPlayer3 = std::make_unique<HumanPlayer>(plName3, gameDeck);
    auto uptrPlayer4 = std::make_unique<HumanPlayer>(plTitle4, plName4, gameDeck);

    // Check MetaData & Wallet
    auto data = player1.getMetaData();
    REQUIRE(data.Total_of_Coins_in_Game   == 0);
    REQUIRE(data.Total_of_Players_in_Game == 8);
    
    uptrPlayer2.reset();
    player1.addCoinsToWallet(5);
    uptrPlayer4->addCoinsToWallet(20);

    REQUIRE(player1.getCoinsOfWallet()    == 5);
    REQUIRE(data.Total_of_Coins_in_Game   == 25);
    REQUIRE(data.Total_of_Players_in_Game == 7);

    uptrPlayer4.reset();
    player4.setCoinsOfWallet(10);

    REQUIRE(data.Total_of_Coins_in_Game   == 15);
    REQUIRE(data.Total_of_Players_in_Game == 6);

    // Check UI
    WARN("Deck methods have already been checked");

    // Check Flags
    player1.Skip_Turn();
    player2.Ready_to_Play();
    uptrPlayer3->Quit_Game();

    REQUIRE(player1.getSkip()         == true);
    REQUIRE(player2.getReady()        == true);
    REQUIRE(uptrPlayer3->getLeaving() == true);

    WARN("End of the test case for the HumanPlayer class");
}


/**
 * @brief Test Case for the Name class
 * 
 */
TEST_CASE("Test Case for the Name class", "[NAME]") {
    WARN("Start of the test case for the Name class");
    
    Name n{"my name"};
    bool result{n.getName() == "my name"};
    REQUIRE(result == true);

    WARN("End of the test case for the Name class");
}


/**
 * @brief Test Case for the PlayerTag class
 * 
 */
TEST_CASE("Test Case for the PlayerTag class", "[PLAYER_TAG]") {
    WARN("Start of the test case for the PlayerTag class");
    
    PlayerTag tag1{ Name{ "The Great Name Player 1" } };
    PlayerTag tag2{ Title{ "Whitebeard" }, Name{ "Edward Newgate" } };
    
    REQUIRE(tag1.getPlayerTag() == "The Great Name Player 1");
    REQUIRE(tag2.getPlayerTag() == "Whitebeard Edward Newgate");

    tag2.removeTitle();
    REQUIRE(tag2.getPlayerTag() == "Edward Newgate");

    tag1.addTitle("title test");
    tag1.addTitle("title test 2");
    REQUIRE(tag1.getPlayerTag() == "title test 2 The Great Name Player 1");

    WARN("End of the test case for the PlayerTag class");
}


/**
 * @brief Test Case for the Score class
 * 
 */
TEST_CASE("Test Case for the Score class", "[SCORE]") {
    WARN("Start of the test case for the Score class");
    
    Score s{};

    // Victory
    s.Increase_Win(); // score += (1 * 0) + 1 = 0 + 1 = 1
    REQUIRE(s.getGamesWon() == 1);
    REQUIRE(s.getScore() == 1);

    s.Increase_Win(); // score += (1 * 1) + 1 = 1 + 2 = 3
    REQUIRE(s.getGamesWon() == 2);
    REQUIRE(s.getScore() == 3);
    s.Increase_Win(); // score += (1 * 2) + 1 = 3 + 3 = 6
    REQUIRE(s.getGamesWon() == 3);
    REQUIRE(s.getScore() == 6);

    // Defeat
    s.Increase_Defeat(); // score -= 0
    REQUIRE(s.getGamesLost() == 1);
    REQUIRE(s.getScore() == 6);

    s.Increase_Defeat(); // score -= 1
    REQUIRE(s.getGamesLost() == 2);
    REQUIRE(s.getScore() == 5);

    // Reset
    s.Reset_Stats();
    bool result{s.getScore() == 0 && s.getGamesWon() == 0 && s.getGamesLost() == 0};
    REQUIRE(result == true);

    WARN("End of the test case for the Score class");
}


/**
 * @brief Test Case for the Title class
 * 
 */
TEST_CASE("Test Case for the Title class", "[TITLE]") {
    WARN("Start of the test case for the Title class");
    
    Title t{"my title"};
    bool result{t.getTitle() == "my title"};
    REQUIRE(result == true);

    WARN("End of the test case for the Title class");
}


/**
 * @brief Test Case for the Wallet class
 * 
 */
TEST_CASE("Test Case for the Wallet class", "[WALLET]") {
    WARN("Start of the test case for the Wallet class");
    
    Wallet w{ Coins{5} };
    bool result{w.getCoins() == 5 and w.isEmpty() == false};
    REQUIRE(result == true);

    w.addCoins(2);
    result = (w.getCoins() == 7 and w.isEmpty() == false);
    REQUIRE(result == true);

    w.removeCoins(7);
    result = (w.getCoins() == 0 and w.isEmpty() == true);
    REQUIRE(result == true);

    w.setCoins(1);
    result = (w.getCoins() == 1 and w.isEmpty() == false);
    REQUIRE(result == true);

    WARN("End of the test case for the Wallet class");
}