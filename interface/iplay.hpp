#ifndef IPLAY_H
#define IPLAY_H

/**
 * Class IPlay_GameBoard
 */
class IPlay_GameBoard
{
public:
    // Constructors
        // None, this is an interface.

    // Destructor - virtual for interface.
    virtual ~IPlay_GameBoard() {}

    // Public Methods - User Interface
    virtual void Play() = 0;

protected:
    // None.

private:
    // None.
};


/**
 * Class IPlay_CasinoDealer
 */
class IPlay_CasinoDealer
{
public:
    // Constructors
        // None, this is an interface.

    // Destructor - virtual for interface.
    virtual ~IPlay_CasinoDealer() {}

    // Public Methods - User Interface
    virtual void Play() = 0;

protected:
    // None.

private:
    // None.
};


/**
 * Class IPlay_CasinoDealer
 */
class IPlay_HumanPlayer
{
public:
    // Constructors
        // None, this is an interface.

    // Destructor - virtual for interface.
    virtual ~IPlay_HumanPlayer() {}

    // Public Methods - User Interface
    virtual void Play() = 0;

protected:
    // None.

private:
    // None.
};

#endif // IPLAY_H
