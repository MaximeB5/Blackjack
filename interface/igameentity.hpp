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
    virtual void Pick_a_Card    (void)  = 0;
    virtual void Skip_Turn      (void)  = 0;
    virtual void Turn_is_Over   (void)  = 0;

protected:
    // None.

private:
    // None.
};

#endif // IGAMEENTITY_H
