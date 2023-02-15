//
//  Condition.hpp
//  SQLite3 Data Access Layer
//
//  Created by Julian Koksal on 2023-02-12.
//

#ifndef Condition_hpp
#define Condition_hpp

#include <any>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "OP.hpp"

namespace DB
{

class Condition
{
    friend class Handle;
public:
    Condition(const std::string& field, const OP op, const std::int64_t value);
    
    Condition(const std::string& field, const OP op, const double value);
    
    Condition(const std::string& field, const OP op, const std::string& value);
    
    Condition(const std::string& field, const OP op,
              const std::vector<std::int64_t>& value);
    
    Condition(const std::string& field, const OP op,
              const std::vector<std::string>& value);
    
private:
    std::string field;
    
    OP op;
    
    std::any value;
    
};

}

#endif /* Condition_hpp */
