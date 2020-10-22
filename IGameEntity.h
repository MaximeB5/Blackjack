#ifndef GAMEENTITY_H
#define GAMEENTITY_H

/**
 * Class GameEntity
 */
class GameEntity
{
public:
    // Constructors
        // None, this is an interface.

    // Destructor
   virtual ~ GameEntity();

    // Public Methods - User Interface
    // virtual void Play() = 0; // POINT TO BE DISCUSSED : member or not of this interface ?
    virtual void Pick_a_Card() = 0;
    virtual void Skip_Turn() = 0;

protected:
    // RAII Methods
    virtual void Init() = 0;
    virtual void Release() = 0;

private:

};

#endif // GAMEENTITY_H
