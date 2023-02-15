//
//  OP.hpp
//  SQLiteDataAccessLayer
//
//  Created by Julian Koksal on 2023-02-15.
//

#ifndef OP_hpp
#define OP_hpp

#include <string>

namespace DB
{

enum class OP : const char
{
    EQ,
    NEQ,
    GT,
    GTE,
    LT,
    LTE,
    IN,
    CONTAINS,
    STARTSWITH,
    ENDSWITH
};

const std::string opStr(OP op);

}

#endif /* OP_hpp */
