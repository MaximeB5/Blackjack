#ifndef TEMPLATES_H
#define TEMPLATES_H

/**
 * @brief template to use the underlying type of an enum class
 * In the case of this project, I aim to provide a way to access the int value of my enum classes.
 * This code is C++14 and comes from the Item 10 of "Effective Modern C++" from Scott Meyers.
 * 
 * @tparam E 
 * @param enumerator 
 * @return constexpr auto 
 */
template<typename E>
constexpr auto toUnderlyingType(E enumerator) noexcept {
    return static_cast<std::underlying_type_t<E> >(enumerator);
}

#endif // TEMPLATES_H