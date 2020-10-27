#ifndef IPLAYER_H
#define IPLAYER_H

/**
 * Class IPlayer
 */
class IPlayer
{
public:
    // Constructors
        // None, this is an interface.

    // Destructor - virtual for interface.
    virtual ~IPlayer() {}

    // Public Methods - User Interface
    virtual void Ready_to_Play() = 0;
    virtual void Quit_Game()     = 0;

protected:
    // None.

private:
    // None.
};

#endif // IPLAYER_H