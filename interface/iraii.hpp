#ifndef IRAII_H
#define IRAII_H

/**
 * Class IRAII
 */
class IRAII
{
public:
    // Constructors
        // None, this is an interface.

    // Destructor - virtual for interface.
    virtual ~IRAII() {}

protected:
    // RAII Methods
    virtual void Init()    = 0;
    virtual void Release() = 0;

private:
    // None.
};

#endif // IRAII_H
