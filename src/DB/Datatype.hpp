//
//  Datatype.hpp
//  SQLiteDataAccessLayer
//
//  Created by Julian Koksal on 2023-02-15.
//

#ifndef Datatype_hpp
#define Datatype_hpp

#include <any>
#include <cstdint>
#include <string>
#include <typeinfo>
#include <type_traits>
#include <vector>

namespace DB
{

/**
 * @brief Represents a value of any SQLite3 datatype.
 */
class Datatype
{
public:
    /**
     * @brief Default constructor.
     */
    Datatype() = default;
    
    /**
     * @brief Constructor.
     *
     * @param value underlying value of the object
     */
    Datatype(const std::int64_t value);
    
    /**
     * @brief Constructor.
     *
     * @param value underlying value of the object
     */
    Datatype(const double value);
    
    /**
     * @brief Constructor.
     *
     * @param value underlying value of the object
     */
    Datatype(const std::string& value);
    
    /**
     * @brief Constructor.
     *
     * @param value underlying value of the object
     */
    Datatype(const std::vector<std::int64_t>& value);
    
    /**
     * @brief Constructor.
     *
     * @param value underlying value of the object
     */
    Datatype(const std::vector<std::string>& value);
    
    /**
     * @brief Gets the underlying value casted to the template type.
     *
     * @return underlying value any casted to T
     */
    template <class T, class = std::enable_if<std::is_same<T, std::int64_t>::value
                                              || std::is_same<T, double>::value
                                              || std::is_same<T, std::string>::value
                                              || std::is_same<T, std::vector<std::int64_t>>::value
                                              || std::is_same<T, std::vector<std::string>>::value>>
    const T cast() const
    {
        return std::any_cast<T>(value_);
    }
    
    /**
     * @brief Gets the underlying type.
     *
     * @return type info of the value
     */
    const std::type_info& type() const;
    
private:
    /**
     * @brief Underlying value of this object.
     */
    std::any value_;
};

}

#endif /* Datatype_hpp */
