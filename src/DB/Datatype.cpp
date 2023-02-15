//
//  Datatype.cpp
//  SQLiteDataAccessLayer
//
//  Created by Julian Koksal on 2023-02-15.
//

#include "Datatype.hpp"

using namespace DB;

Datatype::Datatype(const std::int64_t value)
: value_(value)
{
    
}

Datatype::Datatype(const double value)
: value_(value)
{
    
}

Datatype::Datatype(const std::string& value)
: value_(value)
{
    
}

Datatype::Datatype(const std::vector<std::int64_t>& value)
: value_(value)
{
    
}

Datatype::Datatype(const std::vector<std::string>& value)
: value_(value)
{
    
}

const std::type_info& Datatype::type() const
{
    return value_.type();
}
