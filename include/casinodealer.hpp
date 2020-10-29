#ifndef CASINODEALER_H
#define CASINODEALER_H

// My Includes
#include "../interface/iraii.hpp"
#include "../interface/igameentity.hpp"
#include "name.hpp"

// Includes
    // None for the moment.

/**
 * @brief Class CasinoDealer
 * It inherits from the interfaces IRAII, IGameEntity.
 * 
 */
class CasinoDealer : public IRAII, public IGameEntity
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
    void Pick_a_Card()  override;
    void Skip_Turn()    override;

    // UI
    /**
     * @brief Get the Name object
     * 
     * @return std::string 
     */
    std::string getName(void) const noexcept { return this->_name.getName(); }


protected:
    // Inheritance from IRAII
    void Init()         override;
    void Release()      override;

private:
    // None for the moment.
};

#endif // CASINODEALER_H