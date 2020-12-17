#ifndef SAFEIO_H
#define SAFEIO_H

// My Includes

// Includes
#include <mutex>
#include <string>

class SafeIO{
// Attributes
private:
    std::mutex _m;


// Methods
public:
    // Constructor
    explicit SafeIO(void);

    // Destructor
    ~SafeIO();

    // UI
    void        print   (const std::string& msg)    noexcept;
    std::string ask     (const std::string& msg)    noexcept;
};



#endif // SAFEIO_H