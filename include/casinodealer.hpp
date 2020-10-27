#ifndef CASINODEALER_H
#define CASINODEALER_H

// My Includes
#include "../interface/igameentity.hpp"
#include "name.hpp"

// Includes
    // None for the moment.

/**
 * @brief Class CasinoDealer
 * It inherits from the interface IGameEntity.
 * 
 */
class CasinoDealer : public IGameEntity
{
// Attributes
private:
    Name _name;

// Methods
public:
    // Constructors
    explicit CasinoDealer(const Name& name = Name("Casino Dealer"));

    // Destructor
    virtual ~CasinoDealer();

    // Inheritance from IGameEntity
    void Pick_a_Card() override;
    void Skip_Turn() override;


protected:
    // Inheritance from IGameEntity - RAII Methods
    void Init() override;
    void Release() override;

private:
    // None for the moment.
};

#endif // CASINODEALER_H