#ifndef IGAMEENTITY_H
#define IGAMEENTITY_H

/**
 * Class IGameEntity
 */
class IGameEntity
{
public:
    // Constructors
        // None, this is an interface.

    // Destructor - virtual for interface.
    virtual ~IGameEntity() {}

    // Public Methods - User Interface
    virtual void Pick_a_Card()   = 0;
    virtual void Skip_Turn()     = 0;
    virtual void Turn_is_Over()  = 0;

protected:
    // None.

private:
    // None.
};

#endif // IGAMEENTITY_H
