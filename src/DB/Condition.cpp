//
//  Condition.cpp
//  SQLite3 Data Access Layer
//
//  Created by Julian Koksal on 2023-02-12.
//

#include "Condition.hpp"

using namespace DB;

Condition::Condition(const std::string& field, Op op, const std::int64_t value)
: field(field), op(op), value(value)
{
    
}

Condition::Condition(const std::string& field, Op op, const double value)
: field(field), op(op), value(value)
{
    
}

Condition::Condition(const std::string& field, Op op, const std::string& value)
: field(field), op(op), value(value)
{
    if (op == Op::contains)
    {
        this->value = "%" + value + "%";
    }
    else if (op == Op::startswith)
    {
        this->value = value + "%";
    }
    else if (op == Op::endswith)
    {
        this->value = "%" + value;
    }
}

Condition::Condition(const std::string& field, const Op op,
                     const std::vector<std::string>& value)
: field(field), op(Op::in), value(value)
{
    
}

Condition::Condition(const std::string& field, const Op op,
                     const std::vector<std::int64_t>& value)
: field(field), op(Op::in), value(value)
{
    
}
