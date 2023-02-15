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
#include <vector>

namespace DB
{

class Datatype
{
private:
    const std::any value_;
    
    Datatype(const std::int64_t value);
    
    Datatype(const double value);
    
    Datatype(const std::string& value);
    
    Datatype(const std::vector<std::int64_t>& value);
    
    Datatype(const std::vector<std::string>& value);
    
    template <class T>
    const T& value() const
    {
        return std::any_cast<T>(value_);
    }
    
    const std::type_info& type() const;
};

}

#endif /* Datatype_hpp */
