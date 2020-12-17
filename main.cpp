// My Includes
#include "include/cardvalue.hpp"
#include "include/coins.hpp"
#include "include/constants.hpp"
#include "include/deck.hpp"
#include "include/humanplayer.hpp"
#include "include/templates.hpp"

// Includes
#include <thread>
#include <future>
#include <chrono>
#include <mutex>

class MyCout{
    std::mutex my_mutex;
    static std::mutex staticMutex;
    public:
    void safe_cout(const std::thread::id& id) {
        std::lock_guard<std::mutex> lock(this->my_mutex);      
        std::cout << id << "\n";      
        /*
         block of code which needs mutual exclusion (e.g. open the same 
         file in multiple threads).
        */

        //mutex is automatically released when lock goes out of scope
    }

    static void static_safe_cout(const std::thread::id& id) {
        std::lock_guard<std::mutex> lock(staticMutex);      
        std::cout << id << "\n";      
    }
};

std::mutex MyCout::staticMutex;

int main(int argc, char *argv[])
{
    std::cout << "Blackjack program" << "\n";

    // Test 1
    std::cout << "Test : UINT_MAX from Class Coins : " << Coins::maxValue() << "\n";    // 4 294 967 295

    // Test 2
    for(int i(CARD_VALUE_MIN); i <= CARD_VALUE_MAX; ++i) {
        std::cout << "Card Value : " << i << "\n";
    }

    // Test  3
    unsigned int nbCardToStart = 2;
    std::unique_ptr<Deck> d = std::make_unique<Deck>(nbCardToStart);
    std::unique_ptr<Deck> dd = std::make_unique<Deck>(2);

    // Test 4
    std::cout << "\n\n Test unique ptr == nullptr\n";
    
    auto gameDeck = std::make_shared<Deck>(DeckSpecification::DefaultDeck);
    std::unique_ptr<HumanPlayer> uPlayer; // to be tested for the GameBoard

    if(uPlayer == nullptr) 
        std::cout << "\t\t uPlayer == nullptr\n";

    std::cout << "Test 2\n";
    uPlayer = std::make_unique<HumanPlayer>(PlayerTag{Name{"PlayerName"}}, gameDeck, 20);
    
    if(uPlayer == nullptr) 
        std::cout << "\t\t uPlayer still == nullptr\n";
    else
        std::cout << "\t\t uPlayer allocated well\n";

    uPlayer.reset();
    uPlayer = std::make_unique<HumanPlayer>(PlayerTag{Name{"PlayerName2"}}, gameDeck, 20);
    if(uPlayer == nullptr) 
        std::cout << "\t\t uPlayer failed to reset\n";
    else
        std::cout << "\t\t uPlayer allocated PlayerName2 well after a reseto of the unique ptr\n";

    // Test 5
    CardValue cardVal  = CardValue::Queen;
    auto val = toUnderlyingType(cardVal);
    if(val == 12) 
        std::cout << "cardVal == 12 works\n";
    else
        std::cout << "cardVal == 12 does not work\n";
    

    // Test 6
    std::cout << "\n\n";
    std::cout << "Test async limits : max tasks that can be created\n";
    std::cout << "Main thread id : " << std::this_thread::get_id() << "\n";

    std::vector<std::future<void> > futures;
    MyCout mc;

    for(int i{0}; i < 30; ++i) {
        auto fut = std::async( [&mc] {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            // std::cout << "This thread id : " << std::this_thread::get_id() << "\n";  // cout not protected
            //mc.safe_cout(std::this_thread::get_id());             // works
            MyCout::static_safe_cout(std::this_thread::get_id());   // works
        });
        futures.push_back(std::move(fut));  // fut has no copy constructor to be pushed back in the vector, so we have to move it
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> & fut) {
        fut.wait();
    });

    // Test result :
    //---------------
    // I don't have the same output than https://www.youtube.com/watch?v=_Ll0PIobErE&list=PL1835A90FC78FF8BE&index=5 at 15:23
    // But it seems to work as expected for me

    std::cout << "\n";

    return 0;    
}
