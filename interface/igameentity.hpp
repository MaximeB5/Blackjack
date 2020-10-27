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
    virtual void Pick_a_Card() = 0;
    virtual void Skip_Turn()   = 0;

protected:
    // RAII Methods
    virtual void Init()    = 0;
    virtual void Release() = 0;

private:
    // None.
};

#endif // IGAMEENTITY_H
