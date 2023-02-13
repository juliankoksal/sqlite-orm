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

namespace DB
{

enum class Op : char
{
    eq,
    neq,
    gt,
    gte,
    lt,
    lte,
    in,
    contains,
    startswith,
    endswith
};

class Condition
{
    friend class Handle;
public:
    Condition(const std::string& field, const Op op, const std::int64_t value);
    
    Condition(const std::string& field, const Op op, const double value);
    
    Condition(const std::string& field, const Op op, const std::string& value);
    
    Condition(const std::string& field, const Op op,
              const std::vector<std::string>& value);
    
    Condition(const std::string& field, const Op op,
              const std::vector<std::int64_t>& value);
    
private:
    std::string field;
    
    Op op;
    
    std::any value;
    
};

}

#endif /* Condition_hpp */
