//
//  Condition.cpp
//  SQLite3 Data Access Layer
//
//  Created by Julian Koksal on 2023-02-12.
//

#include "Condition.hpp"

using namespace DB;

Condition::Condition(const std::string& field, OP op, const std::int64_t value)
: field(field), op(op), value(value)
{
    
}

Condition::Condition(const std::string& field, OP op, const double value)
: field(field), op(op), value(value)
{
    
}

Condition::Condition(const std::string& field, OP op, const std::string& value)
: field(field), op(op), value(value)
{
    if (op == OP::CONTAINS)
    {
        this->value = "%" + value + "%";
    }
    else if (op == OP::STARTSWITH)
    {
        this->value = value + "%";
    }
    else if (op == OP::ENDSWITH)
    {
        this->value = "%" + value;
    }
}

Condition::Condition(const std::string& field, const OP op,
                     const std::vector<std::int64_t>& value)
: field(field), op(OP::IN), value(value)
{
    
}

Condition::Condition(const std::string& field, const OP op,
                     const std::vector<std::string>& value)
: field(field), op(OP::IN), value(value)
{
    
}
